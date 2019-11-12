#include "ast/BitwiseOrAssignmentExpression.h"

using namespace hdc;

/* Constructors */
BitwiseOrAssignmentExpression::BitwiseOrAssignmentExpression() {
    /* Empty */
}

BitwiseOrAssignmentExpression::BitwiseOrAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

BitwiseOrAssignmentExpression::BitwiseOrAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
BitwiseOrAssignmentExpression::~BitwiseOrAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseOrAssignmentExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
