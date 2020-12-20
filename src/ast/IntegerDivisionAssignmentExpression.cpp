#include "ast/IntegerDivisionAssignmentExpression.h"

using namespace hdc;

/* Constructors */
IntegerDivisionAssignmentExpression::IntegerDivisionAssignmentExpression() {
    setKind(AST_INTEGER_DIVISION_ASSIGNMENT);
}

IntegerDivisionAssignmentExpression::IntegerDivisionAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_INTEGER_DIVISION_ASSIGNMENT);
}

IntegerDivisionAssignmentExpression::IntegerDivisionAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_INTEGER_DIVISION_ASSIGNMENT);
}

/* Destructors */
IntegerDivisionAssignmentExpression::~IntegerDivisionAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void IntegerDivisionAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
