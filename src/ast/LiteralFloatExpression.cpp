#include "ast/LiteralFloatExpression.h"

using namespace hdc;

/* Constructors */
LiteralFloatExpression::LiteralFloatExpression() {

}

LiteralFloatExpression::LiteralFloatExpression(Token token) {
    this->token = token;
}

/* Destructors */
LiteralFloatExpression::~LiteralFloatExpression() {

}

/* Visitors */
void LiteralFloatExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
