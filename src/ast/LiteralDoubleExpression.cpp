#include "ast/LiteralDoubleExpression.h"

using namespace hdc;

/* Constructors */
LiteralDoubleExpression::LiteralDoubleExpression() {

}

LiteralDoubleExpression::LiteralDoubleExpression(Token token) {
    this->token = token;
}

/* Destructors */
LiteralDoubleExpression::~LiteralDoubleExpression() {

}

/* Visitors */
void LiteralDoubleExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
