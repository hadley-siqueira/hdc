#include "ast/PreDecrementExpression.h"

using namespace hdc;

/* Constructors */
PreDecrementExpression::PreDecrementExpression() {
    setKind(AST_PRE_DECREMENT);
}

PreDecrementExpression::PreDecrementExpression(Expression* expression) : UnaryOperator(expression) {
    setKind(AST_PRE_DECREMENT);
}

PreDecrementExpression::PreDecrementExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    setKind(AST_PRE_DECREMENT);
}

/* Destructors */
PreDecrementExpression::~PreDecrementExpression() {
    /* Empty */
}

/* Visitors */
void PreDecrementExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
