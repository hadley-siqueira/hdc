#include "ast/types/UCharType.h"

using namespace hdc;

UCharType::UCharType() {
    this->kind = AST_UCHAR_TYPE;
}

UCharType::UCharType(Token& token) {
    this->token = token;
    this->kind = AST_UCHAR_TYPE;
}

Type* UCharType::clone() {
    return new UCharType(token);
}

int UCharType::getRank() {
    return 5;
}


void UCharType::accept(Visitor* visitor) {
    visitor->visit(this);
}
