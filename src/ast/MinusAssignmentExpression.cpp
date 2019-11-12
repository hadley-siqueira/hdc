#include "ast/MinusAssignmentExpression.h"

using namespace hdc;

/* Constructors */
MinusAssignmentExpression::MinusAssignmentExpression() {
    /* Empty */
}

MinusAssignmentExpression::MinusAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

MinusAssignmentExpression::MinusAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
MinusAssignmentExpression::~MinusAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void MinusAssignmentExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
