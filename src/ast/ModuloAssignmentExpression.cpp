#include "ast/ModuloAssignmentExpression.h"

using namespace hdc;

/* Constructors */
ModuloAssignmentExpression::ModuloAssignmentExpression() {
    /* Empty */
}

ModuloAssignmentExpression::ModuloAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

ModuloAssignmentExpression::ModuloAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
ModuloAssignmentExpression::~ModuloAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void ModuloAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
