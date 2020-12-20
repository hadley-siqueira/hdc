#include "ast/EqualExpression.h"

using namespace hdc;

/* Constructors */
EqualExpression::EqualExpression() {
    setKind(AST_EQ);
}

EqualExpression::EqualExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_EQ);
}

EqualExpression::EqualExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_EQ);
}

/* Destructors */
EqualExpression::~EqualExpression() {
    /* Empty */
}

/* Visitors */
void EqualExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
