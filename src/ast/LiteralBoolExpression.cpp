#include "ast/LiteralBoolExpression.h"

using namespace hdc;

/* Constructors */
LiteralBoolExpression::LiteralBoolExpression() {

}

LiteralBoolExpression::LiteralBoolExpression(Token token) {
    this->token = token;
}

/* Destructors */
LiteralBoolExpression::~LiteralBoolExpression() {

}

/* Visitors */
void LiteralBoolExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
