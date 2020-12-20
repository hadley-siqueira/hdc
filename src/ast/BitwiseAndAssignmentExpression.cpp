#include "ast/BitwiseAndAssignmentExpression.h"

using namespace hdc;

/* Constructors */
BitwiseAndAssignmentExpression::BitwiseAndAssignmentExpression() {
    setKind(AST_BITWISE_AND_ASSIGNMENT);
}

BitwiseAndAssignmentExpression::BitwiseAndAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_BITWISE_AND_ASSIGNMENT);
}

BitwiseAndAssignmentExpression::BitwiseAndAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_BITWISE_AND_ASSIGNMENT);
}

/* Destructors */
BitwiseAndAssignmentExpression::~BitwiseAndAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseAndAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
