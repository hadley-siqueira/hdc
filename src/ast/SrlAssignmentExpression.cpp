#include "ast/SrlAssignmentExpression.h"

using namespace hdc;

/* Constructors */
SrlAssignmentExpression::SrlAssignmentExpression() {
    /* Empty */
}

SrlAssignmentExpression::SrlAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

SrlAssignmentExpression::SrlAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
SrlAssignmentExpression::~SrlAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void SrlAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
