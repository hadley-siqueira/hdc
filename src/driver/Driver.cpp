#include <fstream>

#include "driver/Driver.h"
#include "parser/Parser.h"

using namespace hdc;

Driver::Driver() {

}

Driver::~Driver() {
    std::map<std::string, SourceFile*>::iterator it;

    it = sourceFiles.begin();

    while (it != sourceFiles.end()) {
        delete it->second;
        ++it;
    }
}

void Driver::compile(std::string pathToMain) {

}

SourceFile* Driver::parseFile(std::string path) {
    Parser parser;
    SourceFile* file;

    if (sourceFiles.count(path) > 0) {
        return sourceFiles[path];
    }

    file = parser.read(path);
    sourceFiles[path] = file;

    return file;
}

bool Driver::fileExists(std::string path) {
    ifstream f(path.c_str());
    return f.good();
}
