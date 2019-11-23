#include "ast/VoidType.h"

using namespace hdc;

VoidType::VoidType() {
    this->kind = AST_VOID_TYPE;
}

VoidType::VoidType(Token& token) {
    this->token = token;
    this->kind = AST_VOID_TYPE;
}

Type* VoidType::clone() {
    return new VoidType(token);
}


void VoidType::accept(Visitor* visitor) {
    visitor->visit(this);
}
