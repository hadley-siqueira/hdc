#include <iostream>
#include <fstream>

#include "driver/Driver.h"
#include "parser/Parser.h"
#include "logger/Logger.h"

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
}

void Driver::setFlags(int argc, char* argv[]) {
    logger.logDriver(true);
    logger.logParser(true);
    logger.logLex(true);

    //mainFilePath = std::string(argv[1]);
    mainFilePath = "/home/hadley/Projetos/hdc/samples/ppm5.hd";
    setRootPathFromMainFile();
}

void Driver::parseProgram() {
    parseImports(parseFile(mainFilePath));
}

void Driver::showLogs() {
    logger.printLogs();
}

void Driver::parseImports(SourceFile* file) {
    for (int i = 0; i < file->n_imports(); ++i) {
        parseImport(file->getImport(i));
    }
}

void Driver::parseImport(Import* import) {
    if (import->isMultipleImport()) {

    } else {
        parseSimpleImport(import);
    }
}

void Driver::parseSimpleImport(Import* import) {
    SourceFile* file;
    std::string path = buildPathForImport(import);

    if (sourceFiles.count(path) > 0) {
        import->setSourceFile(sourceFiles[path]);
    } else {
        file = parseFile(path);
        import->setSourceFile(file);

        parseImports(file);
    }
}

SourceFile* Driver::parseFile(std::string path) {
    Parser parser;
    SourceFile* file;

    if (sourceFiles.count(path) > 0) {
        return sourceFiles[path];
    }

    if (!fileExists(path)) {
        logger.log(LOG_ERROR, "couldn't find file or directory '" + path + "'");
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

void Driver::setRootPathFromMainFile() {
    int c;

    for (c = mainFilePath.size() - 1; c >= 0; --c) {
        if (mainFilePath[c] == pathDelimiter) break;
    }

    for (int i = 0; i < c; ++i) {
        rootPath += mainFilePath[i];
    }

    //std::cout << "root: \033[34m" << rootPath << std::endl;
    //std::cout << "\u001b[0mteste\n";
    //exit(0);
    logger.log(LOG_INTERNAL_DRIVER, "setting rootPath as '" + rootPath + "'");
}
