#include "ast/NotEqualExpression.h"

using namespace hdc;

/* Constructors */
NotEqualExpression::NotEqualExpression() {
    setKind(AST_NE);
}

NotEqualExpression::NotEqualExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_NE);
}

NotEqualExpression::NotEqualExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_NE);
}

/* Destructors */
NotEqualExpression::~NotEqualExpression() {
    /* Empty */
}

/* Visitors */
void NotEqualExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
