#include "ast/SraAssignmentExpression.h"

using namespace hdc;

/* Constructors */
SraAssignmentExpression::SraAssignmentExpression() {
    /* Empty */
}

SraAssignmentExpression::SraAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

SraAssignmentExpression::SraAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
SraAssignmentExpression::~SraAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void SraAssignmentExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
