#include "ast/UnaryMinusExpression.h"

using namespace hdc;

/* Constructors */
UnaryMinusExpression::UnaryMinusExpression() {
    setKind(AST_UNARY_MINUS);
}

UnaryMinusExpression::UnaryMinusExpression(Expression* expression) : UnaryOperator(expression) {
    setKind(AST_UNARY_MINUS);
}

UnaryMinusExpression::UnaryMinusExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    setKind(AST_UNARY_MINUS);
}

/* Destructors */
UnaryMinusExpression::~UnaryMinusExpression() {
    /* Empty */
}

/* Visitors */
void UnaryMinusExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
