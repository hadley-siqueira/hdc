#include "ast/types/Int32Type.h"

using namespace hdc;

Int32Type::Int32Type() {
    this->kind = AST_INT32_TYPE;
}

Int32Type::Int32Type(Token& token) {
    this->token = token;
    this->kind = AST_INT32_TYPE;
}

Type* Int32Type::clone() {
    return new Int32Type(token);
}

int Int32Type::getRank() {
    return 10;
}


void Int32Type::accept(Visitor* visitor) {
    visitor->visit(this);
}
