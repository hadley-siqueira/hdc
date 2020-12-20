#include "ast/types/ShortType.h"

using namespace hdc;

ShortType::ShortType() {
    this->kind = AST_SHORT_TYPE;
}

ShortType::ShortType(Token& token) {
    this->token = token;
    this->kind = AST_SHORT_TYPE;
}

Type* ShortType::clone() {
    return new ShortType(token);
}

int ShortType::getRank() {
    return 7;
}


void ShortType::accept(Visitor* visitor) {
    visitor->visit(this);
}
