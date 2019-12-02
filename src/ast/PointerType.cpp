#include <iostream>

#include "ast/PointerType.h"

using namespace hdc;

PointerType::PointerType() {
    this->kind = AST_POINTER_TYPE;
    this->subtype = NULL;
}

PointerType::PointerType(Type* type) {
    this->subtype = type;
}


PointerType::PointerType(Type* type, Token& token) {
    this->kind = AST_POINTER_TYPE;
    this->subtype = type;
    this->token = token;
}

PointerType::~PointerType() {
    if (subtype != nullptr) {
        delete subtype;
    }
}

void PointerType::setSubtype(Type* type) {
    if (this->subtype != nullptr) {
        delete this->subtype;
    }

    this->subtype = type;
}


Type* PointerType::getSubtype() {
    return subtype;
}

Type*PointerType::clone() {
    return new PointerType(subtype->clone(), token);
}

bool PointerType::equals(Type* other) {
    if (other->getKind() == AST_POINTER_TYPE) {
        PointerType* op = (PointerType*) other;
        return subtype->equals(op->getSubtype());
    }

    return false;
}


void PointerType::accept(Visitor* visitor) {
    visitor->visit(this);
}
