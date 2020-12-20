#include "ast/SrlAssignmentExpression.h"

using namespace hdc;

/* Constructors */
SrlAssignmentExpression::SrlAssignmentExpression() {
    setKind(AST_SRL_ASSIGNMENT);
}

SrlAssignmentExpression::SrlAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_SRL_ASSIGNMENT);
}

SrlAssignmentExpression::SrlAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_SRL_ASSIGNMENT);
}

/* Destructors */
SrlAssignmentExpression::~SrlAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void SrlAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
