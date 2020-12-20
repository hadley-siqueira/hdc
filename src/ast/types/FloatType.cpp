#include "ast/types/FloatType.h"

using namespace hdc;

FloatType::FloatType() {
    this->kind = AST_FLOAT_TYPE;
}

FloatType::FloatType(Token& token) {
    this->token = token;
    this->kind = AST_FLOAT_TYPE;
}

Type* FloatType::clone() {
    return new FloatType(token);
}

int FloatType::getRank() {
    return 18;
}


void FloatType::accept(Visitor* visitor) {
    visitor->visit(this);
}
