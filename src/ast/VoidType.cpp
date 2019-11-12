#include "ast/VoidType.h"

using namespace hdc;

VoidType::VoidType() {
    this->kind = AST_VOID_TYPE;
}

VoidType::VoidType(Token& token) {
    this->token = token;
    this->kind = AST_VOID_TYPE;
}


void VoidType::accept(Visitor* visitor) {
    visitor->visit(this);
}
