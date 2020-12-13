#include "ast/Int8Type.h"

using namespace hdc;

Int8Type::Int8Type() {
    this->kind = AST_INT8_TYPE;
}

Int8Type::Int8Type(Token& token) {
    this->token = token;
    this->kind = AST_INT8_TYPE;
}

Type* Int8Type::clone() {
    return new Int8Type(token);
}

int Int8Type::getRank() {
    return 2;
}


void Int8Type::accept(Visitor* visitor) {
    visitor->visit(this);
}
