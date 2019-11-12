#include "ast/BitwiseNotExpression.h"

using namespace hdc;

/* Constructors */
BitwiseNotExpression::BitwiseNotExpression() {
    /* Empty */
}

BitwiseNotExpression::BitwiseNotExpression(Expression* expression) : UnaryOperator(expression) {
    /* Empty */
}

BitwiseNotExpression::BitwiseNotExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    /* Empty */
}

/* Destructors */
BitwiseNotExpression::~BitwiseNotExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseNotExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
