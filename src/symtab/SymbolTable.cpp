#include "symtab/SymbolTable.h"

using namespace hdc;

bool hdc::SymbolTable::hasParent() {
    return parent != nullptr;
}

void SymbolTable::addClass(Class* klass) {
    symbols[klass->getName()] = new Symbol(klass);
}

void SymbolTable::addDef(Def* def) {
    /*std::string name = def->getName();

    if (symbols.find(name) == symbols.end())
    Symbol* symbol = Symbol.newDef(def);

    symbols[def->getName()] = symbol;*/
}

void SymbolTable::addLocalVariable(LocalVariable* var) {
    symbols[var->getName()] = new Symbol(var);
}

void SymbolTable::addParameter(Parameter* parameter) {
    symbols[parameter->getName()] = new Symbol(parameter);
}

Symbol* SymbolTable::has(std::string& name) {
    if (symbols.count(name) > 0) {
        return symbols[name];
    }

    if (hasParent()) {
        return parent->has(name);
    }

    return nullptr;
}

Symbol* SymbolTable::hasLocalVariable(std::string& name) {
    Symbol* symbol = symbols[name];

    if (symbol != nullptr && symbol->getKind() == SYMBOL_LOCAL_VARIABLE) {
        return symbol;
    }

    if (hasParent()) {
        return parent->hasLocalVariable(name);
    }

    return nullptr;
}

Symbol*SymbolTable::hasLocalVariableOrParameter(const std::string& name) {
    Symbol* symbol = symbols[name];
    SymbolKind kind;

    if (symbol != nullptr) {
        kind = symbol->getKind();

        if (kind == SYMBOL_LOCAL_VARIABLE || kind == SYMBOL_PARAMETER) {
            return symbol;
        }
    }

    if (hasParent()) {
        return parent->hasLocalVariableOrParameter(name);
    }

    return nullptr;
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
