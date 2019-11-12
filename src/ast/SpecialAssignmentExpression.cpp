#include "ast/SpecialAssignmentExpression.h"

using namespace hdc;

/* Constructors */
SpecialAssignmentExpression::SpecialAssignmentExpression() {
    /* Empty */
}

SpecialAssignmentExpression::SpecialAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

SpecialAssignmentExpression::SpecialAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
SpecialAssignmentExpression::~SpecialAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void SpecialAssignmentExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
