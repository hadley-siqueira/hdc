#include "ast/LiteralCharExpression.h"

using namespace hdc;

/* Constructors */
LiteralCharExpression::LiteralCharExpression() {

}

LiteralCharExpression::LiteralCharExpression(Token token) {
    this->token = token;
}

/* Destructors */
LiteralCharExpression::~LiteralCharExpression() {

}

/* Visitors */
void LiteralCharExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
