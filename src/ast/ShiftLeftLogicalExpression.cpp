#include "ast/ShiftLeftLogicalExpression.h"

using namespace hdc;

/* Constructors */
ShiftLeftLogicalExpression::ShiftLeftLogicalExpression() {
    setKind(AST_SLL);
}

ShiftLeftLogicalExpression::ShiftLeftLogicalExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_SLL);
}

ShiftLeftLogicalExpression::ShiftLeftLogicalExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_SLL);
}

/* Destructors */
ShiftLeftLogicalExpression::~ShiftLeftLogicalExpression() {
    /* Empty */
}

/* Visitors */
void ShiftLeftLogicalExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
