#include "ast/ModuloExpression.h"

using namespace hdc;

/* Constructors */
ModuloExpression::ModuloExpression() {
    setKind(AST_MODULO);
}

ModuloExpression::ModuloExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_MODULO);
}

ModuloExpression::ModuloExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_MODULO);
}

/* Destructors */
ModuloExpression::~ModuloExpression() {
    /* Empty */
}

/* Visitors */
void ModuloExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
