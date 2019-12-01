#include "symtab/SymbolTable.h"

using namespace hdc;

/* Constructors */
SymbolTable::SymbolTable() {
    parent = nullptr;
}

SymbolTable::SymbolTable(SymbolTable* parent) {
    this->parent = parent;
}

/* Destructors */
SymbolTable::~SymbolTable() {
    for (std::map<std::string, Symbol*>::iterator it= symbols.begin(); it != symbols.end(); ++it) {
        delete it->second;
    }
}

bool hdc::SymbolTable::hasParent() {
    return parent != nullptr;
}

Symbol* SymbolTable::addClass(Class* klass) {
    Symbol* symbol = new Symbol(klass);
    symbols[klass->getName()] = symbol;
    return symbol;
}

Symbol* SymbolTable::addDef(Def* def) {
    Symbol* symbol = new Symbol(def);
    symbols[def->getName()] = symbol;
    return symbol;
}

Symbol* SymbolTable::addLocalVariable(LocalVariable* var) {
    Symbol* symbol = new Symbol(var);
    symbols[var->getName()] = symbol;
    return symbol;
}

Symbol* SymbolTable::addParameter(Parameter* parameter) {
    Symbol* symbol = new Symbol(parameter);
    symbols[parameter->getName()] = symbol;
    return symbol;
}

Symbol* SymbolTable::addMethod(Def* def) {
    Symbol* symbol = new Symbol(def);
    symbols[def->getName()] = symbol;
    return symbol;
}

Symbol* SymbolTable::addClassVariable(ClassVariable* var) {
    Symbol* symbol = new Symbol(var);
    symbols[var->getName()] = symbol;
    return symbol;
}

Symbol*SymbolTable::add(GlobalVariable* var) {
    Symbol* symbol = new Symbol(var);
    symbols[var->getName()] = symbol;
    return symbol;
}

Symbol* SymbolTable::has(std::string name) {
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

Symbol* SymbolTable::hasClassVariable(std::string& name) {
    Symbol* symbol = symbols[name];

    if (symbol != nullptr && symbol->getKind() == SYMBOL_CLASS_VARIABLE) {
        return symbol;
    }

    if (hasParent()) {
        return parent->hasClassVariable(name);
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
