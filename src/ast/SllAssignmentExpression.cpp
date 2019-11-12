#include "ast/SllAssignmentExpression.h"

using namespace hdc;

/* Constructors */
SllAssignmentExpression::SllAssignmentExpression() {
    /* Empty */
}

SllAssignmentExpression::SllAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

SllAssignmentExpression::SllAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
SllAssignmentExpression::~SllAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void SllAssignmentExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
