#include "ast/SllAssignmentExpression.h"

using namespace hdc;

/* Constructors */
SllAssignmentExpression::SllAssignmentExpression() {
    setKind(AST_SLL_ASSIGNMENT);
}

SllAssignmentExpression::SllAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_SLL_ASSIGNMENT);
}

SllAssignmentExpression::SllAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_SLL_ASSIGNMENT);
}

/* Destructors */
SllAssignmentExpression::~SllAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void SllAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
