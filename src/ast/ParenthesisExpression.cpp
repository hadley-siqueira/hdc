#include "ast/ParenthesisExpression.h"

using namespace hdc;

/* Constructors */
ParenthesisExpression::ParenthesisExpression() {
    setKind(AST_PARENTHESIS);
}

ParenthesisExpression::ParenthesisExpression(Expression* expression) : UnaryOperator(expression) {
    setKind(AST_PARENTHESIS);
}

ParenthesisExpression::ParenthesisExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    setKind(AST_PARENTHESIS);
}

/* Destructors */
ParenthesisExpression::~ParenthesisExpression() {
    /* Empty */
}

/* Visitors */
void ParenthesisExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
