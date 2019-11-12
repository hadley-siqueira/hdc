#include "ast/BitwiseAndExpression.h"

using namespace hdc;

/* Constructors */
BitwiseAndExpression::BitwiseAndExpression() {
    /* Empty */
}

BitwiseAndExpression::BitwiseAndExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

BitwiseAndExpression::BitwiseAndExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
BitwiseAndExpression::~BitwiseAndExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseAndExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
