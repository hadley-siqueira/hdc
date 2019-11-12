#include "ast/BitwiseXorAssignmentExpression.h"

using namespace hdc;

/* Constructors */
BitwiseXorAssignmentExpression::BitwiseXorAssignmentExpression() {
    /* Empty */
}

BitwiseXorAssignmentExpression::BitwiseXorAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

BitwiseXorAssignmentExpression::BitwiseXorAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
BitwiseXorAssignmentExpression::~BitwiseXorAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseXorAssignmentExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
