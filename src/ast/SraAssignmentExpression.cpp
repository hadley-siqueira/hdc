#include "ast/SraAssignmentExpression.h"

using namespace hdc;

/* Constructors */
SraAssignmentExpression::SraAssignmentExpression() {
    setKind(AST_SRA_ASSIGNMENT);
}

SraAssignmentExpression::SraAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_SRA_ASSIGNMENT);
}

SraAssignmentExpression::SraAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_SRA_ASSIGNMENT);
}

/* Destructors */
SraAssignmentExpression::~SraAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void SraAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
