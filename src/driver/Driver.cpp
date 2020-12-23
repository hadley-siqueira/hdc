#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
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
#include "visitors/TACBuilderVisitor.h"

#include "ir/ir.h"
#include "visitors/ir/IRPrettyPrinter.h"
#include "visitors/ast/IRBuilderVisitor.h"

#include "gen/x86_64/gen_x86_64.h"

#include "util/Graph.h"

using namespace hdc;

Driver::Driver() {
    pathDelimiter = '/';
    emitCppFlag = false;
}

Driver::~Driver() {

}

void Driver::run() {
    setRootPathFromMainFile();
    configureSearchPath();

    parseProgram();
    buildSymbolTables();
    //generateTAC();

    if (emitCppFlag) {
        generateCpp();
    } else {
        generateIR();
    }

    //prettyPrintAllFiles();
    //generate_x86_64();
}

void Driver::setFlags(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-cpp") == 0) {
            emitCppFlag = true;
        } else if (strcmp(argv[i], "-log") == 0) {
            ++i;

            if (strcmp(argv[i], "all") == 0) {
                logger.setAllFlags();
            }
        } else if (strcmp(argv[i], "-i") == 0) {
            ++i;

            searchPath.push_back(argv[i]);
        } else if (strstr(argv[i], ".hd") != nullptr) {
            mainFilePath = std::string(argv[i]);
        }
    }
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

void Driver::foobar() {
    std::set<int> bf;

    for (int i = tacs.size() - 1; i >= 0; --i) {
        tacs[i].after = bf;

        if (tacs[i].dst != -1) {
            bf.erase(tacs[i].dst);
        }

        if (tacs[i].src1 != -1) {
            bf.insert(tacs[i].src1);
        }

        if (tacs[i].src2 != -1) {
            bf.insert(tacs[i].src2);
        }

        tacs[i].before = bf;
    }

    // build graph
    Graph<int> g;
    std::set<int>::iterator j, k;

    for (int i = 0; i < tacs.size(); ++i) {
        for (j = tacs[i].before.begin(); j != tacs[i].before.end(); ++j) {
            g.insertNode(*j);
            k = j;
            ++k;

            for ( ; k != tacs[i].before.end(); ++k) {
                g.makeEdge(*j, *k);
            }
        }
    }

    for (int i = 0; i < tacs.size(); ++i) {
        for (j = tacs[i].after.begin(); j != tacs[i].after.end(); ++j) {
            g.insertNode(*j);
            k = j;
            ++k;

            for ( ; k != tacs[i].after.end(); ++k) {
                g.makeEdge(*j, *k);
            }
        }
    }

    g.coloring(8);
    std::cout << g.to_dot();
}

void Driver::buildSymbolTables() {
    SymbolTableBuilderVisitor builder;
    builder.setLogger(&logger);
    program.accept(&builder);
}

void Driver::generateTAC() {
/*    std::map<std::string, SourceFile*>::iterator it;

    for (it = sourceFiles.begin(); it != sourceFiles.end(); ++it) {
        TACBuilderVisitor builder;
        it->second->accept(&builder);
        tacs = builder.getTACs();
        foobar();


        // for debug purposes
        for (int i = 0; i < tacs.size(); ++i) {
            std::cout << tacs[i].to_str_old(true) << '\n';
        }
    }*/
/*
    Graph<int> g;

    g.insertNode('a');
    g.insertNode('b');
    g.insertNode('c');
    g.insertNode('d');
    g.insertNode('e');
    g.insertNode('f');
    g.insertNode('g');

    g.makeEdge('a', 'b');
    g.makeEdge('a', 'd');
    g.makeEdge('a', 'f');
    g.makeEdge('a', 'g');

    g.makeEdge('b', 'c');
    g.makeEdge('b', 'd');
    g.makeEdge('b', 'e');

    g.makeEdge('c', 'd');
    g.makeEdge('c', 'e');

    g.makeEdge('d', 'g');
    g.makeEdge('d', 'f');

    g.makeEdge('e', 'g');
    g.makeEdge('e', 'f');

    g.makeEdge('f', 'g');

    g.coloring(4);
    std::cout << g.to_dot();*/
}

void Driver::generateIR() {
/*    IRBuilderVisitor builder;
    IRProgram* program;
    std::map<std::string, SourceFile*>::iterator it;

    std::cout << "\nGenerating Intermediate Representation...\n\n";

    for (it = sourceFiles.begin(); it != sourceFiles.end(); ++it) {
        it->second->accept(&builder);
    }

    IRPrettyPrinter pp;
    program = builder.getIRProgram();

    program->accept(&pp);

    std::cout << pp.getOutput();
    delete program;*/
}

void Driver::generate_x86_64() {
    Generator_x86_64 gen;

    gen.generate(tacs);
}

void Driver::generateCpp() {
    CppPrinter pp;
    program.accept(&pp);

    pp.save("/tmp/gen.cpp");
    pp.print();
}

void Driver::prettyPrintAllFiles() {
    PrettyPrinter printer;

    program.accept(&printer);
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

    file = program.getSourceFile(path);

    if (file != nullptr) {
        import->setSourceFile(file);
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
            file = program.getSourceFile(path);

            if (file != nullptr) {
                import->addSourceFile(file);
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
    file = program.getSourceFile(path);

    if (file != nullptr) {
        return file;
    }

    if (!fileExists(path)) {
        logger.log(LOG_ERROR, "couldn't find file or directory '" + path + "'");
        logger.quit();
        return nullptr;
    }

    file = parser.read(path);
    program.addSourceFile(file);

    return file;
}

bool Driver::fileExists(std::string path) {
    std::ifstream f(path.c_str());
    return f.good();
}

std::string Driver::buildPathForImport(Import* import) {
    std::string str;
    std::vector<Token> path = import->getPath();

    for (int i = 0; i < path.size(); ++i) {
        str += pathDelimiter;
        str += path[i].getLexem();
    }

    str += ".hd";

    for (int i = 0; i < searchPath.size(); ++i) {
        std::string fullPath = searchPath[i] + str;
        std::cout << "path: " << fullPath << std::endl;

        if (fileExists(fullPath)) {
            return fullPath;
        }
    }

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

std::string Driver::getEnvPath(std::string key) {
    char * val;
    val = std::getenv( key.c_str() );
    std::string retval = "";

    if (val != NULL) {
        retval = val;
    }

    return retval;
}

void Driver::configureSearchPath() {
    searchPath.push_back(rootPath);
    searchPath.push_back(getEnvPath("HDC_PATH"));
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
