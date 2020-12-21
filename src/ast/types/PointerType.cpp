#include <iostream>

#include "ast/types/PointerType.h"

using namespace hdc;

PointerType::PointerType() {
    this->kind = AST_POINTER_TYPE;
    this->subtype = nullptr;
}

PointerType::PointerType(Type* type) {
    this->subtype = type;
    this->kind = AST_POINTER_TYPE;
    type->setParentNode(this);
}


PointerType::PointerType(Type* type, Token& token) {
    this->kind = AST_POINTER_TYPE;
    this->subtype = type;
    this->token = token;
    type->setParentNode(this);
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

int PointerType::getRank() {
    return 21;
}


void PointerType::accept(Visitor* visitor) {
    visitor->visit(this);
}
