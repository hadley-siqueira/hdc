#include "ast/UCharType.h"

using namespace hdc;

UCharType::UCharType() {
    this->kind = AST_UCHAR_TYPE;
}

UCharType::UCharType(Token& token) {
    this->token = token;
    this->kind = AST_UCHAR_TYPE;
}


void UCharType::accept(Visitor* visitor) {
    visitor->visit(this);
}
