#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <string>

#include "driver/Driver.h"
#include "parser/Parser.h"
#include "logger/Logger.h"
#include "visitors/SymbolTableBuilderVisitor.h"
#include "visitors/TypeCheckerVisitor.h"
#include "visitors/CppPrinter.h"
#include "visitors/PrettyPrinter.h"
#include "visitors/TACVisitor.h"
#include "gen/x86_64/gen_x86_64.h"

using namespace hdc;

Driver::Driver() {
    pathDelimiter = '/';
}

Driver::~Driver() {
    std::map<std::string, SourceFile*>::iterator it;

    it = sourceFiles.begin();

    while (it != sourceFiles.end()) {
        delete it->second;
        ++it;
    }
}

void Driver::run() {
    parseProgram();
    buildSymbolTables();
    generateTAC();
    //prettyPrintAllFiles();
    generate_x86_64();
}

void Driver::setFlags(int argc, char* argv[]) {
    logger.logDriver(true);
    logger.logParser(true);
    logger.logLex(true);

    mainFilePath = std::string(argv[1]);
    setRootPathFromMainFile();
}

void Driver::parseProgram() {
    /*Lex p;
    std::vector<Token> v = p.getTokens(mainFilePath);
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i].toStr() << std::endl;
    }*/

    parseImports(parseFile(mainFilePath));
}

void Driver::showLogs() {
    logger.printLogs();
}

void Driver::buildSymbolTables() {
    std::map<std::string, SourceFile*>::iterator it;

    for (it = sourceFiles.begin(); it != sourceFiles.end(); ++it) {
        SymbolTableBuilderVisitor builder;

        builder.setFirstPass(true);
        it->second->accept(&builder);
    }

    for (it = sourceFiles.begin(); it != sourceFiles.end(); ++it) {
        SymbolTableBuilderVisitor builder;

        it->second->accept(&builder);
    }
}

void Driver::generateTAC() {
    std::map<std::string, SourceFile*>::iterator it;

    for (it = sourceFiles.begin(); it != sourceFiles.end(); ++it) {
        TACVisitor builder;
        it->second->accept(&builder);
        tacs = builder.getTACs();
    }
}

void Driver::generate_x86_64() {
    Generator_x86_64 gen;

    gen.generate(tacs);
}

void Driver::prettyPrintAllFiles() {
    std::map<std::string, SourceFile*>::iterator it;

    for (it = sourceFiles.begin(); it != sourceFiles.end(); ++it) {
        PrettyPrinter printer;

        it->second->accept(&printer);
        printer.print();
    }
}

void Driver::parseImports(SourceFile* file) {
    if (file != nullptr) {
        if (file->n_imports() > 0) {
            logger.log(LOG_INTERNAL_DRIVER, "reading imports from '" + file->getPath() + "'");

            for (int i = 0; i < file->n_imports(); ++i) {
                parseImport(file->getImport(i));
            }
        }
    }
}

void Driver::parseImport(Import* import) {
    if (import->isMultipleImport()) {
        parseMultipleImport(import);
    } else {
        parseSimpleImport(import);
    }
}

void Driver::parseSimpleImport(Import* import) {
    SourceFile* file;
    std::string path = buildPathForImport(import);

    if (sourceFiles.count(path) > 0) {
        import->setSourceFile(sourceFiles[path]);
        logger.log(LOG_INTERNAL_DRIVER, "file '" + path + "' was already parsed");
    } else {
        file = parseFile(path);
        import->setSourceFile(file);

        parseImports(file);
    }
}

void Driver::parseMultipleImport(Import* import) {
    int err;
    SourceFile* file;
    std::string basePath;
    std::string path;
    std::vector<std::string> files;

    basePath = buildPathForMultipleImport(import);
    files = getFilesFromDirectory(basePath, err);

    if (files.size() > 0) {
        for (int i = 0; i < files.size(); ++i) {
            path = basePath + files[i];

            if (sourceFiles.count(path) > 0) {
                import->addSourceFile(sourceFiles[path]);
                logger.log(LOG_INTERNAL_DRIVER, "file '" + path + "' was already parsed");
            } else {
                file = parseFile(path);
                import->addSourceFile(file);

                parseImports(file);
            }
        }
    }
}

SourceFile* Driver::parseFile(std::string path) {
    Parser parser;
    SourceFile* file;

    logger.log(LOG_INTERNAL_DRIVER, "parsing file '" + path + "'");

    if (sourceFiles.count(path) > 0) {
        return sourceFiles[path];
    }

    if (!fileExists(path)) {
        logger.log(LOG_ERROR, "couldn't find file or directory '" + path + "'");
        return nullptr;
    }

    file = parser.read(path);
    sourceFiles[path] = file;

    return file;
}

bool Driver::fileExists(std::string path) {
    std::ifstream f(path.c_str());
    return f.good();
}

std::string Driver::buildPathForImport(Import* import) {
    std::string str = rootPath;
    std::vector<Token> path = import->getPath();

    for (int i = 0; i < path.size(); ++i) {
        str += pathDelimiter;
        str += path[i].getLexem();
    }

    str += ".hd";
    return str;
}

std::string Driver::buildPathForMultipleImport(Import* import) {
    std::string str = rootPath;
    std::vector<Token> path = import->getPath();

    for (int i = 0; i < path.size() - 1; ++i) {
        str += pathDelimiter;
        str += path[i].getLexem();
    }

    str += pathDelimiter;
    return str;
}

void Driver::setRootPathFromMainFile() {
    int c;

    for (c = mainFilePath.size() - 1; c >= 0; --c) {
        if (mainFilePath[c] == pathDelimiter) break;
    }

    for (int i = 0; i < c; ++i) {
        rootPath += mainFilePath[i];
    }

    logger.log(LOG_INTERNAL_DRIVER, "setting rootPath as '" + rootPath + "'");
}

std::vector<std::string> Driver::getFilesFromDirectory(std::string path, int& err) {
    std::vector<std::string> files;

    DIR* dirp;
    struct dirent* dp;

    dirp = opendir(path.c_str());

    if (dirp == nullptr) {
        err = 1;
        return files;
    }

    while ((dp = readdir(dirp)) != NULL) {
        char* name = dp->d_name;

        if (strlen(name) > 3) {
            while (*name != '\0') {
                ++name;
            }

            name = name - 3;

            if (strcmp(name, ".hd") == 0) {
                files.push_back(std::string(dp->d_name));
            }
        }
    }

    return files;
}
