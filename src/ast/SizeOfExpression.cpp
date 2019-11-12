#include "ast/SizeOfExpression.h"

using namespace hdc;

/* Constructors */
SizeOfExpression::SizeOfExpression() {
    /* Empty */
}

SizeOfExpression::SizeOfExpression(Expression* expression) : UnaryOperator(expression) {
    /* Empty */
}

SizeOfExpression::SizeOfExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    /* Empty */
}

/* Destructors */
SizeOfExpression::~SizeOfExpression() {
    /* Empty */
}

/* Visitors */
void SizeOfExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
