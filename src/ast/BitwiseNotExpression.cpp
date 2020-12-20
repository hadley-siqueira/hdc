#include "ast/BitwiseNotExpression.h"

using namespace hdc;

/* Constructors */
BitwiseNotExpression::BitwiseNotExpression() {
    setKind(AST_BITWISE_NOT);
}

BitwiseNotExpression::BitwiseNotExpression(Expression* expression) : UnaryOperator(expression) {
    setKind(AST_BITWISE_NOT);
}

BitwiseNotExpression::BitwiseNotExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    setKind(AST_BITWISE_NOT);
}

/* Destructors */
BitwiseNotExpression::~BitwiseNotExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseNotExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
