#include "ast/GreaterThanOrEqualExpression.h"

using namespace hdc;

/* Constructors */
GreaterThanOrEqualExpression::GreaterThanOrEqualExpression() {
    /* Empty */
}

GreaterThanOrEqualExpression::GreaterThanOrEqualExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

GreaterThanOrEqualExpression::GreaterThanOrEqualExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
GreaterThanOrEqualExpression::~GreaterThanOrEqualExpression() {
    /* Empty */
}

/* Visitors */
void GreaterThanOrEqualExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
