#include "ast/AtExpression.h"

using namespace hdc;

/* Constructors */
AtExpression::AtExpression() {
    /* Empty */
}

AtExpression::AtExpression(Expression* expression) : UnaryOperator(expression) {
    /* Empty */
}

AtExpression::AtExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    /* Empty */
}

/* Destructors */
AtExpression::~AtExpression() {
    /* Empty */
}

/* Visitors */
void AtExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
