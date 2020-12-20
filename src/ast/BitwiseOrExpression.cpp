#include "ast/BitwiseOrExpression.h"

using namespace hdc;

/* Constructors */
BitwiseOrExpression::BitwiseOrExpression() {
    setKind(AST_BITWISE_OR);
}

BitwiseOrExpression::BitwiseOrExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_BITWISE_OR);
}

BitwiseOrExpression::BitwiseOrExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_BITWISE_OR);
}

/* Destructors */
BitwiseOrExpression::~BitwiseOrExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseOrExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
