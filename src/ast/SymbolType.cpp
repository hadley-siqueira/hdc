#include "ast/SymbolType.h"

using namespace hdc;

SymbolType::SymbolType() {
    this->kind = AST_SYMBOL_TYPE;
}

SymbolType::SymbolType(Token& token) {
    this->token = token;
    this->kind = AST_SYMBOL_TYPE;
}

Type* SymbolType::clone() {
    return new SymbolType(token);
}


void SymbolType::accept(Visitor* visitor) {
    visitor->visit(this);
}
