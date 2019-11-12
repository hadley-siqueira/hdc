#include "ast/UInt16Type.h"

using namespace hdc;

UInt16Type::UInt16Type() {
    this->kind = AST_UINT16_TYPE;
}

UInt16Type::UInt16Type(Token& token) {
    this->token = token;
    this->kind = AST_UINT16_TYPE;
}


void UInt16Type::accept(Visitor* visitor) {
    visitor->visit(this);
}
