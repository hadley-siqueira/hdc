#include "ast/MinusExpression.h"

using namespace hdc;

/* Constructors */
MinusExpression::MinusExpression() {
    setKind(AST_MINUS);
}

MinusExpression::MinusExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_MINUS);
}

MinusExpression::MinusExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_MINUS);
}

/* Destructors */
MinusExpression::~MinusExpression() {
    /* Empty */
}

/* Visitors */
void MinusExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
