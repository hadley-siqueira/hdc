#include "ast/DivisionAssignmentExpression.h"

using namespace hdc;

/* Constructors */
DivisionAssignmentExpression::DivisionAssignmentExpression() {
    /* Empty */
}

DivisionAssignmentExpression::DivisionAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

DivisionAssignmentExpression::DivisionAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
DivisionAssignmentExpression::~DivisionAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void DivisionAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
