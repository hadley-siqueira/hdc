#include "ast/UShortType.h"

using namespace hdc;

UShortType::UShortType() {
    this->kind = AST_USHORT_TYPE;
}

UShortType::UShortType(Token& token) {
    this->token = token;
    this->kind = AST_USHORT_TYPE;
}


void UShortType::accept(Visitor& visitor) {
    visitor.visit(this);
}
