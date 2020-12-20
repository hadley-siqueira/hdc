#include "ast/MinusAssignmentExpression.h"

using namespace hdc;

/* Constructors */
MinusAssignmentExpression::MinusAssignmentExpression() {
    setKind(AST_MINUS_ASSIGNMENT);
}

MinusAssignmentExpression::MinusAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_MINUS_ASSIGNMENT);
}

MinusAssignmentExpression::MinusAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_MINUS_ASSIGNMENT);
}

/* Destructors */
MinusAssignmentExpression::~MinusAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void MinusAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
