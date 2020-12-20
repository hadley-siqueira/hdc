#include "ast/BitwiseOrAssignmentExpression.h"

using namespace hdc;

/* Constructors */
BitwiseOrAssignmentExpression::BitwiseOrAssignmentExpression() {
    setKind(AST_BITWISE_OR_ASSIGNMENT);
}

BitwiseOrAssignmentExpression::BitwiseOrAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_BITWISE_OR_ASSIGNMENT);
}

BitwiseOrAssignmentExpression::BitwiseOrAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_BITWISE_OR_ASSIGNMENT);
}

/* Destructors */
BitwiseOrAssignmentExpression::~BitwiseOrAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseOrAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
