#include "ast/LiteralSymbolExpression.h"

using namespace hdc;

/* Constructors */
LiteralSymbolExpression::LiteralSymbolExpression() {

}

LiteralSymbolExpression::LiteralSymbolExpression(Token token) {
    this->token = token;
}

/* Destructors */
LiteralSymbolExpression::~LiteralSymbolExpression() {

}

/* Visitors */
void LiteralSymbolExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
