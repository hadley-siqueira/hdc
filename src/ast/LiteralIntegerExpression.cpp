#include "ast/LiteralIntegerExpression.h"

using namespace hdc;

/* Constructors */
LiteralIntegerExpression::LiteralIntegerExpression() {

}

LiteralIntegerExpression::LiteralIntegerExpression(Token token) {
    this->token = token;
}

/* Destructors */
LiteralIntegerExpression::~LiteralIntegerExpression() {

}

/* Visitors */
void LiteralIntegerExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
