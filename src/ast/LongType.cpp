#include "ast/LongType.h"

using namespace hdc;

LongType::LongType() {
    this->kind = AST_LONG_TYPE;
}

LongType::LongType(Token& token) {
    this->token = token;
    this->kind = AST_LONG_TYPE;
}

Type* LongType::clone() {
    return new LongType(token);
}

int LongType::getRank() {
    return 15;
}


void LongType::accept(Visitor* visitor) {
    visitor->visit(this);
}
