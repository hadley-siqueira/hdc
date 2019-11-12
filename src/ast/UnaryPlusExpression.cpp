#include "ast/UnaryPlusExpression.h"

using namespace hdc;

/* Constructors */
UnaryPlusExpression::UnaryPlusExpression() {
    /* Empty */
}

UnaryPlusExpression::UnaryPlusExpression(Expression* expression) : UnaryOperator(expression) {
    /* Empty */
}

UnaryPlusExpression::UnaryPlusExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    /* Empty */
}

/* Destructors */
UnaryPlusExpression::~UnaryPlusExpression() {
    /* Empty */
}

/* Visitors */
void UnaryPlusExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
