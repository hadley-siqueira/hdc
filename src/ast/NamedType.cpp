#include "ast/NamedType.h"

using namespace hdc;

NamedType::NamedType() {
    this->kind = AST_NAMED_TYPE;
    this->name = nullptr;
    classDescriptor = nullptr;
    structDescriptor = nullptr;
}

NamedType::NamedType(IdentifierExpression* name) {
    this->kind = AST_NAMED_TYPE;
    this->name = name;
}

NamedType::~NamedType() {
    delete name;
}

Type* NamedType::clone() {
    return new NamedType(new IdentifierExpression(this->name));
}

int NamedType::getRank() {
    return 22;
}

void NamedType::setDescriptor(Class *klass) {
    classDescriptor = klass;
}

void NamedType::setDescriptor(Struct *st) {
    structDescriptor = st;
}

void *NamedType::getDescriptor() {
    if (classDescriptor != nullptr) {
        return classDescriptor;
    } else if (structDescriptor != nullptr) {
        return structDescriptor;
    }

    return nullptr;
}

SymbolTable *NamedType::getSymbolTable() {
    if (classDescriptor != nullptr) {
        return classDescriptor->getSymbolTable();
    } else if (structDescriptor != nullptr) {
        return structDescriptor->getSymbolTable();
    }

    return nullptr;
}

void NamedType::accept(Visitor* visitor) {
    visitor->visit(this);
}

IdentifierExpression* NamedType::getName() const {
    return name;
}

void NamedType::setName(IdentifierExpression* value) {
    if (name != nullptr) {
        delete name;
    }

    name = value;
}
