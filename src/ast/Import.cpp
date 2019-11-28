#include "ast/SourceFile.h"
#include "ast/Import.h"
#include <iostream>
#include <sstream>

using namespace hdc;

bool Import::hasAlias() {
    return alias.getLexem().size() > 0;
}

void Import::add(hdc::Token& token) {
    path.push_back(token);
}


void Import::set_alias(hdc::Token& token) {
    alias = token;
}

std::string Import::str() {
    std::stringstream output;
    int i;

    output << "import ";

    for (i = 0; i < path.size() - 1; ++i) {
        output << path[i].getLexem() << ".";
    }

    output << path[i].getLexem();

    if (hasAlias()) {
        output << " as " << alias.getLexem();
    }

    return output.str();
}

bool Import::isMultipleImport() {
    if (path.size() > 0) {
        return path[path.size() - 1].getKind() == TK_TIMES;
    }

    return false;
}

void Import::accept(Visitor* visitor) {
    visitor->visit(this);
}

SourceFile* Import::getSourceFile() const {
    return sourceFile;
}

void Import::setSourceFile(SourceFile* value) {
    sourceFile = value;
}

std::vector<hdc::Token> Import::getPath() const
{
    return path;
}

void Import::setPath(const std::vector<hdc::Token>& value)
{
    path = value;
}

void Import::addSourceFile(SourceFile* file) {
    sourceFiles.push_back(file);
}
