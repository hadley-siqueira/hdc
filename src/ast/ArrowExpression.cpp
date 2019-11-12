#include "ast/ArrowExpression.h"

using namespace hdc;

/* Constructors */
ArrowExpression::ArrowExpression() {
    /* Empty */
}

ArrowExpression::ArrowExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

ArrowExpression::ArrowExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
ArrowExpression::~ArrowExpression() {
    /* Empty */
}

/* Visitors */
void ArrowExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
