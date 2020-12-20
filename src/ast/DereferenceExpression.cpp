#include "ast/DereferenceExpression.h"

using namespace hdc;

/* Constructors */
DereferenceExpression::DereferenceExpression() {
    setKind(AST_DEREFERENCE);
}

DereferenceExpression::DereferenceExpression(Expression* expression) : UnaryOperator(expression) {
    setKind(AST_DEREFERENCE);
}

DereferenceExpression::DereferenceExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    setKind(AST_DEREFERENCE);
}

/* Destructors */
DereferenceExpression::~DereferenceExpression() {
    /* Empty */
}

/* Visitors */
void DereferenceExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
