#include "ast/PreIncrementExpression.h"

using namespace hdc;

/* Constructors */
PreIncrementExpression::PreIncrementExpression() {
    setKind(AST_PRE_INCREMENT);
}

PreIncrementExpression::PreIncrementExpression(Expression* expression) : UnaryOperator(expression) {
    setKind(AST_PRE_INCREMENT);
}

PreIncrementExpression::PreIncrementExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    setKind(AST_PRE_INCREMENT);
}

/* Destructors */
PreIncrementExpression::~PreIncrementExpression() {
    /* Empty */
}

/* Visitors */
void PreIncrementExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
