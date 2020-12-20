#include "ast/DivisionExpression.h"

using namespace hdc;

/* Constructors */
DivisionExpression::DivisionExpression() {
    setKind(AST_DIVISION);
}

DivisionExpression::DivisionExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_DIVISION);
}

DivisionExpression::DivisionExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_DIVISION);
}

/* Destructors */
DivisionExpression::~DivisionExpression() {
    /* Empty */
}

/* Visitors */
void DivisionExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
