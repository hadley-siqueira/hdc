#include "ast/DolarExpression.h"

using namespace hdc;

/* Constructors */
DolarExpression::DolarExpression() {
    /* Empty */
}

DolarExpression::DolarExpression(Expression* expression) : UnaryOperator(expression) {
    /* Empty */
}

DolarExpression::DolarExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    /* Empty */
}

/* Destructors */
DolarExpression::~DolarExpression() {
    /* Empty */
}

/* Visitors */
void DolarExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
