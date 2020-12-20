#include "ast/AtExpression.h"

using namespace hdc;

/* Constructors */
AtExpression::AtExpression() {
    setKind(AST_AT);
}

AtExpression::AtExpression(Expression* expression) : UnaryOperator(expression) {
    setKind(AST_AT);
}

AtExpression::AtExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    setKind(AST_AT);
}

/* Destructors */
AtExpression::~AtExpression() {
    /* Empty */
}

/* Visitors */
void AtExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
