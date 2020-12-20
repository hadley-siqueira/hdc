#include "ast/AssignmentExpression.h"

using namespace hdc;

/* Constructors */
AssignmentExpression::AssignmentExpression() {
    setKind(AST_ASSIGNMENT);
}

AssignmentExpression::AssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_ASSIGNMENT);
}

AssignmentExpression::AssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_ASSIGNMENT);
}

/* Destructors */
AssignmentExpression::~AssignmentExpression() {
    /* Empty */
}

/* Visitors */
void AssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
