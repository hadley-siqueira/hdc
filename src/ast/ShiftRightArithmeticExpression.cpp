#include "ast/ShiftRightArithmeticExpression.h"

using namespace hdc;

/* Constructors */
ShiftRightArithmeticExpression::ShiftRightArithmeticExpression() {
    setKind(AST_SRA);
}

ShiftRightArithmeticExpression::ShiftRightArithmeticExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_SRA);
}

ShiftRightArithmeticExpression::ShiftRightArithmeticExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_SRA);
}

/* Destructors */
ShiftRightArithmeticExpression::~ShiftRightArithmeticExpression() {
    /* Empty */
}

/* Visitors */
void ShiftRightArithmeticExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
