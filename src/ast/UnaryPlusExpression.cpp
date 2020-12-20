#include "ast/UnaryPlusExpression.h"

using namespace hdc;

/* Constructors */
UnaryPlusExpression::UnaryPlusExpression() {
    setKind(AST_UNARY_PLUS);
}

UnaryPlusExpression::UnaryPlusExpression(Expression* expression) : UnaryOperator(expression) {
    setKind(AST_UNARY_PLUS);
}

UnaryPlusExpression::UnaryPlusExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    setKind(AST_UNARY_PLUS);
}

/* Destructors */
UnaryPlusExpression::~UnaryPlusExpression() {
    /* Empty */
}

/* Visitors */
void UnaryPlusExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
