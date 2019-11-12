#include "ast/ParenthesisExpression.h"

using namespace hdc;

/* Constructors */
ParenthesisExpression::ParenthesisExpression() {
    /* Empty */
}

ParenthesisExpression::ParenthesisExpression(Expression* expression) : UnaryOperator(expression) {
    /* Empty */
}

ParenthesisExpression::ParenthesisExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    /* Empty */
}

/* Destructors */
ParenthesisExpression::~ParenthesisExpression() {
    /* Empty */
}

/* Visitors */
void ParenthesisExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
