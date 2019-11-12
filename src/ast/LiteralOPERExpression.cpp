#include "ast/LiteralOPERExpression.h"

using namespace hdc;

/* Constructors */
LiteralOPERExpression::LiteralOPERExpression() {

}

LiteralOPERExpression::LiteralOPERExpression(Token token) {
    this->token = token;
}

/* Destructors */
LiteralOPERExpression::~LiteralOPERExpression() {

}

/* Visitors */
void LiteralOPERExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
