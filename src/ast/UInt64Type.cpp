#include "ast/UInt64Type.h"

using namespace hdc;

UInt64Type::UInt64Type() {
    this->kind = AST_UINT64_TYPE;
}

UInt64Type::UInt64Type(Token& token) {
    this->token = token;
    this->kind = AST_UINT64_TYPE;
}

Type* UInt64Type::clone() {
    return new UInt64Type(token);
}


void UInt64Type::accept(Visitor* visitor) {
    visitor->visit(this);
}
