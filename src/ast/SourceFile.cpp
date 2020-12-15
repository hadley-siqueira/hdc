#include "ast/SourceFile.h"

using namespace hdc;

SourceFile::SourceFile() {
    this->symbolTable = nullptr;
}

SourceFile::SourceFile(std::string& path) {
    this->path = path;
    this->symbolTable = nullptr;
}

SourceFile::~SourceFile() {
    for (int i = 0; i < imports.size(); ++i) {
        delete imports[i];
    }

    for (int i = 0; i < defs.size(); ++i) {
        delete defs[i];
    }

    for (int i = 0; i < globalVariables.size(); ++i) {
        delete globalVariables[i];
    }

    delete symbolTable;
}

void SourceFile::addImport(Import* import) {
    imports.push_back(import);
}

void SourceFile::addClass(Class* klass) {
    classes.push_back(klass);
    klass->setSourceFile(this);
}

void SourceFile::addStruct(Struct* s) {
    structures.push_back(s);
}

void SourceFile::addDef(Def* def) {
    defs.push_back(def);
    def->setFile(this);
}

void SourceFile::addGlobalVariable(GlobalVariable* var) {
    globalVariables.push_back(var);
    var->setSourceFile(this);
}

void SourceFile::addGlobalConstant(GlobalConstant* var) {
    globalConstants.push_back(var);
    var->setSourceFile(this);
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

int SourceFile::n_structures() {
    return structures.size();
}

int SourceFile::n_global_variables() {
    return globalVariables.size();
}

int SourceFile::n_global_constants() {
    return globalConstants.size();
}

std::string SourceFile::getPath() {
    return path;
}

Class* SourceFile::getClass(int i) {
    if (i < classes.size()) {
        return classes[i];
    }

    return nullptr;
}

Struct*SourceFile::getStruct(int i) {
    if (i < structures.size()) {
        return structures[i];
    }

    return nullptr;
}

Def* SourceFile::getDef(int i) {
    if (i < defs.size()) {
        return defs[i];
    } else {
        return nullptr;
    }
}


Import* SourceFile::getImport(int i) {
    if (i < imports.size()) {
        return imports[i];
    } else {
        return nullptr;
    }
}

GlobalVariable* SourceFile::getGlobalVariable(int i) {
    if (i < globalVariables.size()) {
        return globalVariables[i];
    } else {
        return nullptr;
    }
}

GlobalConstant* SourceFile::getGlobalConstant(int i) {
    if (i < globalConstants.size()) {
        return globalConstants[i];
    } else {
        return nullptr;
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
