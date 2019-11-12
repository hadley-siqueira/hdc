#include "ast/IntegerDivisionAssignmentExpression.h"

using namespace hdc;

/* Constructors */
IntegerDivisionAssignmentExpression::IntegerDivisionAssignmentExpression() {
    /* Empty */
}

IntegerDivisionAssignmentExpression::IntegerDivisionAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

IntegerDivisionAssignmentExpression::IntegerDivisionAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
IntegerDivisionAssignmentExpression::~IntegerDivisionAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void IntegerDivisionAssignmentExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
