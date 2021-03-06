#include "ast/types/UShortType.h"

using namespace hdc;

UShortType::UShortType() {
    this->kind = AST_USHORT_TYPE;
}

UShortType::UShortType(Token& token) {
    this->token = token;
    this->kind = AST_USHORT_TYPE;
}

Type* UShortType::clone() {
    return new UShortType(token);
}

int UShortType::getRank() {
    return 9;
}


void UShortType::accept(Visitor* visitor) {
    visitor->visit(this);
}
