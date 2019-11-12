#include "ast/LongType.h"

using namespace hdc;

LongType::LongType() {
    this->kind = AST_LONG_TYPE;
}

LongType::LongType(Token& token) {
    this->token = token;
    this->kind = AST_LONG_TYPE;
}


void LongType::accept(Visitor* visitor) {
    visitor->visit(this);
}
