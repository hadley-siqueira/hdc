#include "ast/CharType.h"

using namespace hdc;

CharType::CharType() {
    this->kind = AST_CHAR_TYPE;
}

CharType::CharType(Token& token) {
    this->token = token;
    this->kind = AST_CHAR_TYPE;
}


void CharType::accept(Visitor* visitor) {
    visitor->visit(this);
}
