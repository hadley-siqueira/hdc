#include "ast/UnaryMinusExpression.h"

using namespace hdc;

/* Constructors */
UnaryMinusExpression::UnaryMinusExpression() {
    /* Empty */
}

UnaryMinusExpression::UnaryMinusExpression(Expression* expression) : UnaryOperator(expression) {
    /* Empty */
}

UnaryMinusExpression::UnaryMinusExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    /* Empty */
}

/* Destructors */
UnaryMinusExpression::~UnaryMinusExpression() {
    /* Empty */
}

/* Visitors */
void UnaryMinusExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
