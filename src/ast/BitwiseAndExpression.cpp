#include "ast/BitwiseAndExpression.h"

using namespace hdc;

/* Constructors */
BitwiseAndExpression::BitwiseAndExpression() {
    setKind(AST_BITWISE_AND);
}

BitwiseAndExpression::BitwiseAndExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_BITWISE_AND);
}

BitwiseAndExpression::BitwiseAndExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_BITWISE_AND);
}

/* Destructors */
BitwiseAndExpression::~BitwiseAndExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseAndExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
