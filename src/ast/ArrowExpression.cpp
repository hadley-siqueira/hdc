#include "ast/ArrowExpression.h"

using namespace hdc;

/* Constructors */
ArrowExpression::ArrowExpression() {
    setKind(AST_ARROW);
}

ArrowExpression::ArrowExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_ARROW);
}

ArrowExpression::ArrowExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_ARROW);
}

/* Destructors */
ArrowExpression::~ArrowExpression() {
    /* Empty */
}

/* Visitors */
void ArrowExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
