#include <iostream>

#include "ast/PointerType.h"

using namespace hdc;

PointerType::PointerType() {
    this->kind = AST_POINTER_TYPE;
    this->subtype = NULL;
}


PointerType::PointerType(Type* type, Token& token) {
    this->kind = AST_POINTER_TYPE;
    this->subtype = type;
    this->token = token;
}

PointerType::~PointerType() {
    if (subtype != NULL) {
        delete subtype;
    }
}


Type* PointerType::getSubtype() {
    return subtype;
}

Type*PointerType::clone() {
    return new PointerType(subtype->clone(), token);
}


void PointerType::accept(Visitor* visitor) {
    visitor->visit(this);
}
