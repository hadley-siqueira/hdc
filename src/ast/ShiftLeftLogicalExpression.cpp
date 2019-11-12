#include "ast/ShiftLeftLogicalExpression.h"

using namespace hdc;

/* Constructors */
ShiftLeftLogicalExpression::ShiftLeftLogicalExpression() {
    /* Empty */
}

ShiftLeftLogicalExpression::ShiftLeftLogicalExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

ShiftLeftLogicalExpression::ShiftLeftLogicalExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
ShiftLeftLogicalExpression::~ShiftLeftLogicalExpression() {
    /* Empty */
}

/* Visitors */
void ShiftLeftLogicalExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
