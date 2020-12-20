#include "ast/GreaterThanOrEqualExpression.h"

using namespace hdc;

/* Constructors */
GreaterThanOrEqualExpression::GreaterThanOrEqualExpression() {
    setKind(AST_GE);
}

GreaterThanOrEqualExpression::GreaterThanOrEqualExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_GE);
}

GreaterThanOrEqualExpression::GreaterThanOrEqualExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_GE);
}

/* Destructors */
GreaterThanOrEqualExpression::~GreaterThanOrEqualExpression() {
    /* Empty */
}

/* Visitors */
void GreaterThanOrEqualExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
