#include "ast/types/UInt32Type.h"

using namespace hdc;

UInt32Type::UInt32Type() {
    this->kind = AST_UINT32_TYPE;
}

UInt32Type::UInt32Type(Token& token) {
    this->token = token;
    this->kind = AST_UINT32_TYPE;
}

Type* UInt32Type::clone() {
    return new UInt32Type(token);
}

int UInt32Type::getRank() {
    return 12;
}


void UInt32Type::accept(Visitor* visitor) {
    visitor->visit(this);
}
