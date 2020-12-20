#include "ast/types/PrimitiveType.h"

using namespace hdc;

PrimitiveType::PrimitiveType() {
    this->kind = AST_PRIMITIVE_TYPE;
}


PrimitiveType::PrimitiveType(Token& token) {
    this->token = token;
}


void PrimitiveType::accept(Visitor* visitor) {
    visitor->visit(this);
}
