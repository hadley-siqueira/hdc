#include "ast/Int16Type.h"

using namespace hdc;

Int16Type::Int16Type() {
    this->kind = AST_INT16_TYPE;
}

Int16Type::Int16Type(Token& token) {
    this->token = token;
    this->kind = AST_INT16_TYPE;
}


void Int16Type::accept(Visitor* visitor) {
    visitor->visit(this);
}
