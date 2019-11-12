#include "ast/AssignmentExpression.h"

using namespace hdc;

/* Constructors */
AssignmentExpression::AssignmentExpression() {
    /* Empty */
}

AssignmentExpression::AssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

AssignmentExpression::AssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
AssignmentExpression::~AssignmentExpression() {
    /* Empty */
}

/* Visitors */
void AssignmentExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
