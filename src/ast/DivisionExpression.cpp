#include "ast/DivisionExpression.h"

using namespace hdc;

/* Constructors */
DivisionExpression::DivisionExpression() {
    /* Empty */
}

DivisionExpression::DivisionExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

DivisionExpression::DivisionExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
DivisionExpression::~DivisionExpression() {
    /* Empty */
}

/* Visitors */
void DivisionExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
