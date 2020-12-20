#include "ast/SpecialAssignmentExpression.h"

using namespace hdc;

/* Constructors */
SpecialAssignmentExpression::SpecialAssignmentExpression() {
    setKind(AST_SPECIAL_ASSIGNMENT);
}

SpecialAssignmentExpression::SpecialAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_SPECIAL_ASSIGNMENT);
}

SpecialAssignmentExpression::SpecialAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_SPECIAL_ASSIGNMENT);
}

/* Destructors */
SpecialAssignmentExpression::~SpecialAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void SpecialAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
