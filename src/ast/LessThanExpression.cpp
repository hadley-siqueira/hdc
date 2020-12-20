#include "ast/LessThanExpression.h"

using namespace hdc;

/* Constructors */
LessThanExpression::LessThanExpression() {
    setKind(AST_LT);
}

LessThanExpression::LessThanExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_LT);
}

LessThanExpression::LessThanExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_LT);
}

/* Destructors */
LessThanExpression::~LessThanExpression() {
    /* Empty */
}

/* Visitors */
void LessThanExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
