#include "ast/BitwiseOrExpression.h"

using namespace hdc;

/* Constructors */
BitwiseOrExpression::BitwiseOrExpression() {
    /* Empty */
}

BitwiseOrExpression::BitwiseOrExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

BitwiseOrExpression::BitwiseOrExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
BitwiseOrExpression::~BitwiseOrExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseOrExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
