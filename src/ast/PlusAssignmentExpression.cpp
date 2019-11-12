#include "ast/PlusAssignmentExpression.h"

using namespace hdc;

/* Constructors */
PlusAssignmentExpression::PlusAssignmentExpression() {
    /* Empty */
}

PlusAssignmentExpression::PlusAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

PlusAssignmentExpression::PlusAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
PlusAssignmentExpression::~PlusAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void PlusAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
