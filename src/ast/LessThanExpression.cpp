#include "ast/LessThanExpression.h"

using namespace hdc;

/* Constructors */
LessThanExpression::LessThanExpression() {
    /* Empty */
}

LessThanExpression::LessThanExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

LessThanExpression::LessThanExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
LessThanExpression::~LessThanExpression() {
    /* Empty */
}

/* Visitors */
void LessThanExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
