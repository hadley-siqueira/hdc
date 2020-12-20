#include "ast/SizeOfExpression.h"

using namespace hdc;

/* Constructors */
SizeOfExpression::SizeOfExpression() {
    setKind(AST_SIZEOF);
}

SizeOfExpression::SizeOfExpression(Expression* expression) : UnaryOperator(expression) {
    setKind(AST_SIZEOF);
}

SizeOfExpression::SizeOfExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    setKind(AST_SIZEOF);
}

/* Destructors */
SizeOfExpression::~SizeOfExpression() {
    /* Empty */
}

/* Visitors */
void SizeOfExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
