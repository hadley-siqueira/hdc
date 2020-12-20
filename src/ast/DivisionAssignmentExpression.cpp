#include "ast/DivisionAssignmentExpression.h"

using namespace hdc;

/* Constructors */
DivisionAssignmentExpression::DivisionAssignmentExpression() {
    setKind(AST_DIVISION_ASSIGNMENT);
}

DivisionAssignmentExpression::DivisionAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_DIVISION_ASSIGNMENT);
}

DivisionAssignmentExpression::DivisionAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_DIVISION_ASSIGNMENT);
}

/* Destructors */
DivisionAssignmentExpression::~DivisionAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void DivisionAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
