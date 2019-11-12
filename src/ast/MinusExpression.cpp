#include "ast/MinusExpression.h"

using namespace hdc;

/* Constructors */
MinusExpression::MinusExpression() {
    /* Empty */
}

MinusExpression::MinusExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

MinusExpression::MinusExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
MinusExpression::~MinusExpression() {
    /* Empty */
}

/* Visitors */
void MinusExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
