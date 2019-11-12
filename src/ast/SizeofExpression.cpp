#include "ast/SizeofExpression.h"

using namespace hdc;

/* Constructors */
SizeofExpression::SizeofExpression() {
    /* Empty */
}

SizeofExpression::SizeofExpression(Expression* expression) : UnaryOperator(expression) {
    /* Empty */
}

SizeofExpression::SizeofExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    /* Empty */
}

/* Destructors */
SizeofExpression::~SizeofExpression() {
    /* Empty */
}

/* Visitors */
void SizeofExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
