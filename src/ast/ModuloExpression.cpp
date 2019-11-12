#include "ast/ModuloExpression.h"

using namespace hdc;

/* Constructors */
ModuloExpression::ModuloExpression() {
    /* Empty */
}

ModuloExpression::ModuloExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

ModuloExpression::ModuloExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
ModuloExpression::~ModuloExpression() {
    /* Empty */
}

/* Visitors */
void ModuloExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
