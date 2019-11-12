#include "ast/ShiftRightLogicalExpression.h"

using namespace hdc;

/* Constructors */
ShiftRightLogicalExpression::ShiftRightLogicalExpression() {
    /* Empty */
}

ShiftRightLogicalExpression::ShiftRightLogicalExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

ShiftRightLogicalExpression::ShiftRightLogicalExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
ShiftRightLogicalExpression::~ShiftRightLogicalExpression() {
    /* Empty */
}

/* Visitors */
void ShiftRightLogicalExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
