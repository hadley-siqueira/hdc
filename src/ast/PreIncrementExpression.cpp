#include "ast/PreIncrementExpression.h"

using namespace hdc;

/* Constructors */
PreIncrementExpression::PreIncrementExpression() {
    /* Empty */
}

PreIncrementExpression::PreIncrementExpression(Expression* expression) : UnaryOperator(expression) {
    /* Empty */
}

PreIncrementExpression::PreIncrementExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    /* Empty */
}

/* Destructors */
PreIncrementExpression::~PreIncrementExpression() {
    /* Empty */
}

/* Visitors */
void PreIncrementExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
