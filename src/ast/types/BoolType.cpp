#include "ast/types/BoolType.h"

using namespace hdc;

BoolType::BoolType() {
    this->kind = AST_BOOL_TYPE;
}

BoolType::BoolType(Token& token) {
    this->token = token;
    this->kind = AST_BOOL_TYPE;
}

Type* BoolType::clone() {
    return new BoolType(token);
}

int BoolType::getRank() {
    return 1;
}


void BoolType::accept(Visitor* visitor) {
    visitor->visit(this);
}
