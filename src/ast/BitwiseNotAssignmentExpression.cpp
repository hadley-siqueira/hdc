#include "ast/BitwiseNotAssignmentExpression.h"

using namespace hdc;

/* Constructors */
BitwiseNotAssignmentExpression::BitwiseNotAssignmentExpression() {
    /* Empty */
}

BitwiseNotAssignmentExpression::BitwiseNotAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

BitwiseNotAssignmentExpression::BitwiseNotAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
BitwiseNotAssignmentExpression::~BitwiseNotAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseNotAssignmentExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
