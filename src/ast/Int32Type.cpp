#include "ast/Int32Type.h"

using namespace hdc;

Int32Type::Int32Type() {
    this->kind = AST_INT32_TYPE;
}

Int32Type::Int32Type(Token& token) {
    this->token = token;
    this->kind = AST_INT32_TYPE;
}


void Int32Type::accept(Visitor* visitor) {
    visitor->visit(this);
}
