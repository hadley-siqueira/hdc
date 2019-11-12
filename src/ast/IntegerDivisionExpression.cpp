#include "ast/IntegerDivisionExpression.h"

using namespace hdc;

/* Constructors */
IntegerDivisionExpression::IntegerDivisionExpression() {
    /* Empty */
}

IntegerDivisionExpression::IntegerDivisionExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

IntegerDivisionExpression::IntegerDivisionExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
IntegerDivisionExpression::~IntegerDivisionExpression() {
    /* Empty */
}

/* Visitors */
void IntegerDivisionExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
