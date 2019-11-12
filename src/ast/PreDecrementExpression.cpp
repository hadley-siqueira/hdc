#include "ast/PreDecrementExpression.h"

using namespace hdc;

/* Constructors */
PreDecrementExpression::PreDecrementExpression() {
    /* Empty */
}

PreDecrementExpression::PreDecrementExpression(Expression* expression) : UnaryOperator(expression) {
    /* Empty */
}

PreDecrementExpression::PreDecrementExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    /* Empty */
}

/* Destructors */
PreDecrementExpression::~PreDecrementExpression() {
    /* Empty */
}

/* Visitors */
void PreDecrementExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
