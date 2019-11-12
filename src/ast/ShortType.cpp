#include "ast/ShortType.h"

using namespace hdc;

ShortType::ShortType() {
    this->kind = AST_SHORT_TYPE;
}

ShortType::ShortType(Token& token) {
    this->token = token;
    this->kind = AST_SHORT_TYPE;
}


void ShortType::accept(Visitor* visitor) {
    visitor->visit(this);
}
