#include "ast/DereferenceExpression.h"

using namespace hdc;

/* Constructors */
DereferenceExpression::DereferenceExpression() {
    /* Empty */
}

DereferenceExpression::DereferenceExpression(Expression* expression) : UnaryOperator(expression) {
    /* Empty */
}

DereferenceExpression::DereferenceExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    /* Empty */
}

/* Destructors */
DereferenceExpression::~DereferenceExpression() {
    /* Empty */
}

/* Visitors */
void DereferenceExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
