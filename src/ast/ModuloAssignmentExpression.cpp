#include "ast/ModuloAssignmentExpression.h"

using namespace hdc;

/* Constructors */
ModuloAssignmentExpression::ModuloAssignmentExpression() {
    setKind(AST_MODULO_ASSIGNMENT);
}

ModuloAssignmentExpression::ModuloAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_MODULO_ASSIGNMENT);
}

ModuloAssignmentExpression::ModuloAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_MODULO_ASSIGNMENT);
}

/* Destructors */
ModuloAssignmentExpression::~ModuloAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void ModuloAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
