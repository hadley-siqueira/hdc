#include "ast/GreaterThanExpression.h"

using namespace hdc;

/* Constructors */
GreaterThanExpression::GreaterThanExpression() {
    setKind(AST_GT);
}

GreaterThanExpression::GreaterThanExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_GT);
}

GreaterThanExpression::GreaterThanExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_GT);
}

/* Destructors */
GreaterThanExpression::~GreaterThanExpression() {
    /* Empty */
}

/* Visitors */
void GreaterThanExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
