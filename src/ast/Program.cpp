#include "ast/Program.h"

using namespace hdc;

Program::Program() {
    functionCounter = 0;
    classCounter = 0;
    setKind(AST_PROGRAM);
}

Program::~Program() {
    std::map<std::string, SourceFile*>::iterator it;

    for (it = sourceFiles.begin(); it != sourceFiles.end(); ++it) {
        delete it->second;
    }
}

void Program::addSourceFile(SourceFile *sfile) {
    std::string path = sfile->getPath();
    sourceFiles[path] = sfile;
}

bool Program::hasSourceFile(std::string path) {
    return sourceFiles.count(path) > 0;
}

SourceFile *Program::getSourceFile(std::string path) {
    if (hasSourceFile(path)) {
        return sourceFiles[path];
    }

    return nullptr;
}

std::map<std::string, SourceFile*>::iterator Program::begin() {
    return sourceFiles.begin();
}

std::map<std::string, SourceFile*>::iterator Program::end() {
    return sourceFiles.end();
}

void Program::accept(Visitor *visitor) {
    visitor->visit(this);
}
