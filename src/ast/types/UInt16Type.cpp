#include "ast/types/UInt16Type.h"

using namespace hdc;

UInt16Type::UInt16Type() {
    this->kind = AST_UINT16_TYPE;
}

UInt16Type::UInt16Type(Token& token) {
    this->token = token;
    this->kind = AST_UINT16_TYPE;
}

Type*UInt16Type::clone() {
    return new UInt16Type(token);
}

int UInt16Type::getRank() {
    return 8;
}


void UInt16Type::accept(Visitor* visitor) {
    visitor->visit(this);
}
