#include <iostream>

#include "ast/types/NamedType.h"

using namespace hdc;

NamedType::NamedType() {
    this->kind = AST_NAMED_TYPE;
    this->name = nullptr;
}

NamedType::NamedType(IdentifierExpression* name) {
    this->kind = AST_NAMED_TYPE;
    this->name = name;
}

NamedType::~NamedType() {
    delete name;
}

Type* NamedType::clone() {
    NamedType* copy = new NamedType(new IdentifierExpression(this->name));
    return copy;
}

bool NamedType::equals(Type *other) {
    Symbol* s1;
    Symbol* s2;
    NamedType* n;

    if (kind == other->getKind()) {
        n = (NamedType*) other;

        s1 = getName()->getSymbol();
        s2 = n->getName()->getSymbol();

        if (s1 != nullptr && s2 != nullptr) {
            return s1->getDescriptor() == s2->getDescriptor();
        }
    }

    return false;
}

int NamedType::getRank() {
    return 22;
}

void *NamedType::getDescriptor() {
    Symbol* sym = name->getSymbol();

    if (sym != nullptr) {
        return sym->getDescriptor();
    }

    return nullptr;
}

SymbolTable *NamedType::getSymbolTable() {
    Symbol* sym;
    Class* c;

    sym = name->getSymbol(); std::cout << name->getName() << "<---" << std::endl;

    if (sym != nullptr) {
        switch (sym->getKind()) {
        case SYMBOL_CLASS:
            c = (Class*) sym->getDescriptor();
            return c->getSymbolTable();

        default:
            break;
        }
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
