#include "symtab/SymbolTableStack.h"

using namespace hdc;

hdc::SymbolTableStack::SymbolTableStack() {
    current = nullptr;
    symbolTable = nullptr;
}

SymbolTableStack::SymbolTableStack(SymbolTable** symbolTable) {
    current = *symbolTable;
    this->symbolTable = symbolTable;
}

void SymbolTableStack::push(SymbolTable* symbolTable) {
    symbolTableStack.push(symbolTable);
    current = symbolTable;
    setSymbolTable();
}

void SymbolTableStack::pop() {
    symbolTableStack.pop();
    current = symbolTableStack.top();
    setSymbolTable();
}

void SymbolTableStack::setSymbolTable() {
    if (symbolTable != nullptr) {
        *symbolTable = current;
    }
}
