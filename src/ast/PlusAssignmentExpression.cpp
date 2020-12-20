#include "ast/PlusAssignmentExpression.h"

using namespace hdc;

/* Constructors */
PlusAssignmentExpression::PlusAssignmentExpression() {
    setKind(AST_PLUS_ASSIGNMENT);
}

PlusAssignmentExpression::PlusAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_PLUS_ASSIGNMENT);
}

PlusAssignmentExpression::PlusAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_PLUS_ASSIGNMENT);
}

/* Destructors */
PlusAssignmentExpression::~PlusAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void PlusAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
