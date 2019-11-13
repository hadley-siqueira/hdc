#include "symtab/SymbolTable.h"

using namespace hdc;

bool hdc::SymbolTable::hasParent() {
    return parent != nullptr;
}

void SymbolTable::addDef(Def* def) {
    /*std::string name = def->getName();

    if (symbols.find(name) == symbols.end())
    Symbol* symbol = Symbol.newDef(def);

    symbols[def->getName()] = symbol;*/
}

Symbol* SymbolTable::has(std::string& name) {
    if (symbols.count(name) > 0) {
        return symbols[name];
    }

    if (hasParent()) {
        return parent->has(name);
    }
}

SymbolTable* SymbolTable::getParent() const {
    return parent;
}

void SymbolTable::setParent(SymbolTable* parent) {
    this->parent = parent;
}

SourceFile* SymbolTable::getSourceFile() const {
    return sourceFile;
}

void SymbolTable::setSourceFile(SourceFile* value) {
    sourceFile = value;
}
