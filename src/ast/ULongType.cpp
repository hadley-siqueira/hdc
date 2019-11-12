#include "ast/ULongType.h"

using namespace hdc;

ULongType::ULongType() {
    this->kind = AST_ULONG_TYPE;
}

ULongType::ULongType(Token& token) {
    this->token = token;
    this->kind = AST_ULONG_TYPE;
}


void ULongType::accept(Visitor* visitor) {
    visitor->visit(this);
}
