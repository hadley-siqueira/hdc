#include "ast/ShiftRightLogicalExpression.h"

using namespace hdc;

/* Constructors */
ShiftRightLogicalExpression::ShiftRightLogicalExpression() {
    setKind(AST_SRL);
}

ShiftRightLogicalExpression::ShiftRightLogicalExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_SRL);
}

ShiftRightLogicalExpression::ShiftRightLogicalExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_SRL);
}

/* Destructors */
ShiftRightLogicalExpression::~ShiftRightLogicalExpression() {
    /* Empty */
}

/* Visitors */
void ShiftRightLogicalExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
