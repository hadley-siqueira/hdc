#include "ast/BitwiseAndAssignmentExpression.h"

using namespace hdc;

/* Constructors */
BitwiseAndAssignmentExpression::BitwiseAndAssignmentExpression() {
    /* Empty */
}

BitwiseAndAssignmentExpression::BitwiseAndAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

BitwiseAndAssignmentExpression::BitwiseAndAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
BitwiseAndAssignmentExpression::~BitwiseAndAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseAndAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
