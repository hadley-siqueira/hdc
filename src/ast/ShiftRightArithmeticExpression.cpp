#include "ast/ShiftRightArithmeticExpression.h"

using namespace hdc;

/* Constructors */
ShiftRightArithmeticExpression::ShiftRightArithmeticExpression() {
    /* Empty */
}

ShiftRightArithmeticExpression::ShiftRightArithmeticExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

ShiftRightArithmeticExpression::ShiftRightArithmeticExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
ShiftRightArithmeticExpression::~ShiftRightArithmeticExpression() {
    /* Empty */
}

/* Visitors */
void ShiftRightArithmeticExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
