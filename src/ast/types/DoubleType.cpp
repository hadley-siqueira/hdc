#include "ast/types/DoubleType.h"

using namespace hdc;

DoubleType::DoubleType() {
    this->kind = AST_DOUBLE_TYPE;
}

DoubleType::DoubleType(Token& token) {
    this->token = token;
    this->kind = AST_DOUBLE_TYPE;
}

Type* DoubleType::clone() {
    return new DoubleType(token);
}

int DoubleType::getRank() {
    return 19;
}


void DoubleType::accept(Visitor* visitor) {
    visitor->visit(this);
}
