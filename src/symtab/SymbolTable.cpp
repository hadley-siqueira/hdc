#include <iostream>

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

void SymbolTable::dump() {
    std::map<std::string, Symbol*>::iterator it;

    std::cout << "{";
    for (it = symbols.begin(); it != symbols.end(); ++it) {
        std::cout << it->first << ", ";
    }

    std::cout << "} -> ";

    if (hasParent()) {
        parent->dump();
    } else {
        std::cout << "\n\n";
    }
}

Symbol* SymbolTable::add(Class* klass) {
    Symbol* symbol = new Symbol(klass);
    symbols[klass->getName()] = symbol;
    return symbol;
}

Symbol* SymbolTable::add(Def* def) {
    Symbol* symbol = new Symbol(def);
    symbols[def->getName()] = symbol;
    return symbol;
}

Symbol* SymbolTable::add(LocalVariable* var) {
    Symbol* symbol = new Symbol(var);
    symbols[var->getName()] = symbol;
    return symbol;
}

Symbol* SymbolTable::add(Parameter* parameter) {
    Symbol* symbol = new Symbol(parameter);
    symbols[parameter->getName()] = symbol;
    return symbol;
}

Symbol* SymbolTable::add(ClassVariable* var) {
    Symbol* symbol = new Symbol(var);
    symbols[var->getName()] = symbol;
    return symbol;
}

Symbol*SymbolTable::add(GlobalVariable* var) {
    Symbol* symbol = new Symbol(var);
    symbols[var->getName()] = symbol;
    return symbol;
}

// searches on local file and all its imports
Symbol* SymbolTable::has(std::string name) {
    if (symbols.count(name) > 0) {
        return symbols[name];
    }

    if (hasParent()) {
        return parent->has(name);
    } else if (sourceFile != nullptr) {
        Symbol* symbol;

        for (int i = 0; i < sourceFile->n_imports(); ++i) {
            Import* import = sourceFile->getImport(i);

            if (import->isMultipleImport()) {

            } else {
                SourceFile* f = import->getSourceFile();
                std::cout << "searching for " << name << " on ";
                f->getSymbolTable()->dump();
                symbol = f->getSymbolTable()->hasLocal(name);

                if (symbol != nullptr) {
                    return symbol;
                }
            }
        }
    }

    return nullptr;
}

// searches only on the file itself without its imports
Symbol *SymbolTable::hasLocal(std::string name) {
    if (symbols.count(name) > 0) {
        return symbols[name];
    }

    if (hasParent()) {
        return parent->hasLocal(name);
    }

    return nullptr;
}

Symbol* SymbolTable::hasLocalVariable(std::string& name) {
    if (symbols.count(name) > 0) {
        Symbol* symbol = symbols[name];

        if (symbol != nullptr && symbol->getKind() == SYMBOL_LOCAL_VARIABLE) {
            return symbol;
        }
    }

    if (hasParent()) {
        return parent->hasLocalVariable(name);
    }

    return nullptr;
}

Symbol*SymbolTable::hasLocalVariableOrParameter(const std::string& name) {
    Symbol* symbol;
    SymbolKind kind;

    if (symbols.count(name) > 0) {
        symbol = symbols[name];
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
    if (symbols.count(name) > 0) {
        Symbol* symbol = symbols[name];

        if (symbol != nullptr && symbol->getKind() == SYMBOL_CLASS_VARIABLE) {
            return symbol;
        }
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
