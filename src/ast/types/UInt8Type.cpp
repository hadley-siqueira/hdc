#include "ast/types/UInt8Type.h"

using namespace hdc;

UInt8Type::UInt8Type() {
    this->kind = AST_UINT8_TYPE;
}

UInt8Type::UInt8Type(Token& token) {
    this->token = token;
    this->kind = AST_UINT8_TYPE;
}

Type* UInt8Type::clone() {
    return new UInt8Type(token);
}

int UInt8Type::getRank() {
    return 4;
}


void UInt8Type::accept(Visitor* visitor) {
    visitor->visit(this);
}
