#include "ast/BoolType.h"

using namespace hdc;

BoolType::BoolType() {
    this->kind = AST_BOOL_TYPE;
}

BoolType::BoolType(Token& token) {
    this->token = token;
    this->kind = AST_BOOL_TYPE;
}


void BoolType::accept(Visitor* visitor) {
    visitor->visit(this);
}