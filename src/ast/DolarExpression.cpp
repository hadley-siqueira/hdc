#include "ast/DolarExpression.h"

using namespace hdc;

/* Constructors */
DolarExpression::DolarExpression() {
    setKind(AST_DOLAR);
}

DolarExpression::DolarExpression(Expression* expression) : UnaryOperator(expression) {
    setKind(AST_DOLAR);
}

DolarExpression::DolarExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    setKind(AST_DOLAR);
}

/* Destructors */
DolarExpression::~DolarExpression() {
    /* Empty */
}

/* Visitors */
void DolarExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
