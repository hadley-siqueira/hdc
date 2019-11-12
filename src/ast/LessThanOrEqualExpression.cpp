#include "ast/LessThanOrEqualExpression.h"

using namespace hdc;

/* Constructors */
LessThanOrEqualExpression::LessThanOrEqualExpression() {
    /* Empty */
}

LessThanOrEqualExpression::LessThanOrEqualExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

LessThanOrEqualExpression::LessThanOrEqualExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
LessThanOrEqualExpression::~LessThanOrEqualExpression() {
    /* Empty */
}

/* Visitors */
void LessThanOrEqualExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
