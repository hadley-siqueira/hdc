#include "ast/LessThanOrEqualExpression.h"

using namespace hdc;

/* Constructors */
LessThanOrEqualExpression::LessThanOrEqualExpression() {
    setKind(AST_LE);
}

LessThanOrEqualExpression::LessThanOrEqualExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_LE);
}

LessThanOrEqualExpression::LessThanOrEqualExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_LE);
}

/* Destructors */
LessThanOrEqualExpression::~LessThanOrEqualExpression() {
    /* Empty */
}

/* Visitors */
void LessThanOrEqualExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
