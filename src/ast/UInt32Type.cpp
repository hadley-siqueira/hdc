#include "ast/UInt32Type.h"

using namespace hdc;

UInt32Type::UInt32Type() {
    this->kind = AST_UINT32_TYPE;
}

UInt32Type::UInt32Type(Token& token) {
    this->token = token;
    this->kind = AST_UINT32_TYPE;
}


void UInt32Type::accept(Visitor* visitor) {
    visitor->visit(this);
}
