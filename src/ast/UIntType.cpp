#include "ast/UIntType.h"

using namespace hdc;

UIntType::UIntType() {
    this->kind = AST_UINT_TYPE;
}

UIntType::UIntType(Token& token) {
    this->token = token;
    this->kind = AST_UINT_TYPE;
}


void UIntType::accept(Visitor* visitor) {
    visitor->visit(this);
}
