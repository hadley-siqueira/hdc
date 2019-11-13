#include "ast/SourceFile.h"

using namespace hdc;

SourceFile::SourceFile() {
    this->symbolTable = nullptr;
}

SourceFile::SourceFile(std::string& path) {
    this->path = path;
    this->symbolTable = nullptr;
    this->symbolTable->setSourceFile(this);
}

SourceFile::~SourceFile() {
    for (int i = 0; i < imports.size(); ++i) {
        delete imports[i];
    }

    for (int i = 0; i < defs.size(); ++i) {
        delete defs[i];
    }

    delete symbolTable;
}

void SourceFile::addImport(Import* import) {
    imports.push_back(import);
}

void SourceFile::addClass(Class* klass) {
    classes.push_back(klass);
}

void SourceFile::addDef(Def* def) {
    defs.push_back(def);
    def->set_file(this);
}


int SourceFile::n_defs() {
    return defs.size();
}


int SourceFile::n_imports() {
    return imports.size();
}

int SourceFile::n_classes() {
    return classes.size();
}

std::string SourceFile::getPath() {
    return path;
}

Class* SourceFile::getClass(int i) {
    if (i < classes.size()) {
        return classes[i];
    }

    return NULL;
}

Def* SourceFile::getDef(int i) {
    if (i < defs.size()) {
        return defs[i];
    } else {
        return NULL;
    }
}


Import* SourceFile::getImport(int i) {
    if (i < imports.size()) {
        return imports[i];
    } else {
        return NULL;
    }
}

void SourceFile::accept(Visitor* visitor) {
    visitor->visit(this);
}

SymbolTable* SourceFile::getSymbolTable() const {
    return symbolTable;
}

void SourceFile::setSymbolTable(SymbolTable* value) {
    symbolTable = value;
    symbolTable->setSourceFile(this);
}
