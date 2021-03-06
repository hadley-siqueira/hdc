#include "ast/types/Int64Type.h"

using namespace hdc;

Int64Type::Int64Type() {
    this->kind = AST_INT64_TYPE;
}

Int64Type::Int64Type(Token& token) {
    this->token = token;
    this->kind = AST_INT64_TYPE;
}

Type*Int64Type::clone() {
    return new Int64Type(token);
}

int Int64Type::getRank() {
    return 14;
}


void Int64Type::accept(Visitor* visitor) {
    visitor->visit(this);
}
