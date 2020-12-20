#include "ast/IntegerDivisionExpression.h"

using namespace hdc;

/* Constructors */
IntegerDivisionExpression::IntegerDivisionExpression() {
    setKind(AST_INTEGER_DIVISION);
}

IntegerDivisionExpression::IntegerDivisionExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_INTEGER_DIVISION);
}

IntegerDivisionExpression::IntegerDivisionExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_INTEGER_DIVISION);
}

/* Destructors */
IntegerDivisionExpression::~IntegerDivisionExpression() {
    /* Empty */
}

/* Visitors */
void IntegerDivisionExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
