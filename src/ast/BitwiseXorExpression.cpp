#include "ast/BitwiseXorExpression.h"

using namespace hdc;

/* Constructors */
BitwiseXorExpression::BitwiseXorExpression() {
    /* Empty */
}

BitwiseXorExpression::BitwiseXorExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

BitwiseXorExpression::BitwiseXorExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
BitwiseXorExpression::~BitwiseXorExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseXorExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
