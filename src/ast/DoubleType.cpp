#include "ast/DoubleType.h"

using namespace hdc;

DoubleType::DoubleType() {
    this->kind = AST_DOUBLE_TYPE;
}

DoubleType::DoubleType(Token& token) {
    this->token = token;
    this->kind = AST_DOUBLE_TYPE;
}


void DoubleType::accept(Visitor* visitor) {
    visitor->visit(this);
}
