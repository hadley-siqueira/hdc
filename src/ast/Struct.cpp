#include "ast/Struct.h"

using namespace hdc;

Struct::Struct() {
    parent = nullptr;
    file = nullptr;
    symbolTable = nullptr;
}

Struct::~Struct() {
    delete parent;
    delete file;
    delete symbolTable;
}

void Struct::setName(Token& token) {
    this->name = token;
}

void Struct::setParent(IdentifierExpression* parent) {
    this->parent = parent;
}

std::string Struct::getName() {
    return name.getLexem();
}

IdentifierExpression*Struct::getParent() {
    return this->parent;
}

StructField*Struct::getField(int i) {
    if (i < fields.size()) {
        return fields[i];
    }

    return nullptr;
}

int Struct::getLine() {
    return name.getLine();
}

int Struct::getColumn() {
    return name.getColumn();
}

bool Struct::hasParent() {
    return parent != nullptr;
}

int Struct::n_fields() {
    return fields.size();
}

void Struct::addField(StructField* field) {
    fields.push_back(field);
}

void Struct::accept(Visitor* visitor) {
    visitor->visit(this);
}

SymbolTable*Struct::getSymbolTable() const {
    return symbolTable;
}

void Struct::setSymbolTable(SymbolTable* value) {
    if (symbolTable != nullptr) {
        delete symbolTable;
    }

    symbolTable = value;
}
