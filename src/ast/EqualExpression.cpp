#include "ast/EqualExpression.h"

using namespace hdc;

/* Constructors */
EqualExpression::EqualExpression() {
    /* Empty */
}

EqualExpression::EqualExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

EqualExpression::EqualExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
EqualExpression::~EqualExpression() {
    /* Empty */
}

/* Visitors */
void EqualExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
