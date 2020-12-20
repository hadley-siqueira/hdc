#include "ast/types/ULongType.h"

using namespace hdc;

ULongType::ULongType() {
    this->kind = AST_ULONG_TYPE;
}

ULongType::ULongType(Token& token) {
    this->token = token;
    this->kind = AST_ULONG_TYPE;
}

Type* ULongType::clone() {
    return new ULongType(token);
}

int ULongType::getRank() {
    return 17;
}


void ULongType::accept(Visitor* visitor) {
    visitor->visit(this);
}
