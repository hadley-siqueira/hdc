#include "ast/GreaterThanExpression.h"

using namespace hdc;

/* Constructors */
GreaterThanExpression::GreaterThanExpression() {
    /* Empty */
}

GreaterThanExpression::GreaterThanExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

GreaterThanExpression::GreaterThanExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
GreaterThanExpression::~GreaterThanExpression() {
    /* Empty */
}

/* Visitors */
void GreaterThanExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
