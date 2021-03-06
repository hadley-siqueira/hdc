#include "ast/types/IntType.h"

using namespace hdc;

IntType::IntType() {
    this->kind = AST_INT_TYPE;
}

IntType::IntType(Token& token) {
    this->token = token;
    this->kind = AST_INT_TYPE;
}

Type *IntType::clone() {
    return new IntType(token);
}

int IntType::getRank() {
    return 11;
}

void IntType::accept(Visitor* visitor) {
    visitor->visit(this);
}
