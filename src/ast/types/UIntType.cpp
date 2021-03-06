#include "ast/types/UIntType.h"

using namespace hdc;

UIntType::UIntType() {
    this->kind = AST_UINT_TYPE;
}

UIntType::UIntType(Token& token) {
    this->token = token;
    this->kind = AST_UINT_TYPE;
}

Type* UIntType::clone() {
    return new UIntType(token);
}

int UIntType::getRank() {
    return 13;
}


void UIntType::accept(Visitor* visitor) {
    visitor->visit(this);
}
