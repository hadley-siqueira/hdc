#include "ast/NotEqualExpression.h"

using namespace hdc;

/* Constructors */
NotEqualExpression::NotEqualExpression() {
    /* Empty */
}

NotEqualExpression::NotEqualExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

NotEqualExpression::NotEqualExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
NotEqualExpression::~NotEqualExpression() {
    /* Empty */
}

/* Visitors */
void NotEqualExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
