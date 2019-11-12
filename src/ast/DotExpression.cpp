#include "ast/DotExpression.h"

using namespace hdc;

/* Constructors */
DotExpression::DotExpression() {
    /* Empty */
}

DotExpression::DotExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

DotExpression::DotExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
DotExpression::~DotExpression() {
    /* Empty */
}

/* Visitors */
void DotExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
