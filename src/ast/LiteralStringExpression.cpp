#include "ast/LiteralStringExpression.h"

using namespace hdc;

/* Constructors */
LiteralStringExpression::LiteralStringExpression() {

}

LiteralStringExpression::LiteralStringExpression(Token token) {
    this->token = token;
}

/* Destructors */
LiteralStringExpression::~LiteralStringExpression() {

}

/* Visitors */
void LiteralStringExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
