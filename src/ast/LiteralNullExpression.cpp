#include "ast/LiteralNullExpression.h"

using namespace hdc;

/* Constructors */
LiteralNullExpression::LiteralNullExpression() {

}

LiteralNullExpression::LiteralNullExpression(Token token) {
    this->token = token;
}

/* Destructors */
LiteralNullExpression::~LiteralNullExpression() {

}

/* Visitors */
void LiteralNullExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
