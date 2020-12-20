#include "ast/BitwiseNotAssignmentExpression.h"

using namespace hdc;

/* Constructors */
BitwiseNotAssignmentExpression::BitwiseNotAssignmentExpression() {
    setKind(AST_BITWISE_NOT_ASSIGNMENT);
}

BitwiseNotAssignmentExpression::BitwiseNotAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_BITWISE_NOT_ASSIGNMENT);
}

BitwiseNotAssignmentExpression::BitwiseNotAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_BITWISE_NOT_ASSIGNMENT);
}

/* Destructors */
BitwiseNotAssignmentExpression::~BitwiseNotAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseNotAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
