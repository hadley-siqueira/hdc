#include "ast/BitwiseXorAssignmentExpression.h"

using namespace hdc;

/* Constructors */
BitwiseXorAssignmentExpression::BitwiseXorAssignmentExpression() {
    setKind(AST_BITWISE_XOR_ASSIGNMENT);
}

BitwiseXorAssignmentExpression::BitwiseXorAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_BITWISE_XOR_ASSIGNMENT);
}

BitwiseXorAssignmentExpression::BitwiseXorAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_BITWISE_XOR_ASSIGNMENT);
}

/* Destructors */
BitwiseXorAssignmentExpression::~BitwiseXorAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseXorAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
