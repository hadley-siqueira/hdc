#include "ast/LiteralSymbolExpression.h"

using namespace hdc;

/* Constructors */
LiteralSymbolExpression::LiteralSymbolExpression() {
    setKind(AST_LITERAL_SYMBOL);
}

LiteralSymbolExpression::LiteralSymbolExpression(Token token) {
    this->token = token;
    setKind(AST_LITERAL_SYMBOL);
}

/* Destructors */
LiteralSymbolExpression::~LiteralSymbolExpression() {

}

/* Visitors */
void LiteralSymbolExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
