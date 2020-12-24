#include "ast/AssignmentExpression.h"

using namespace hdc;

/* Constructors */
AssignmentExpression::AssignmentExpression() {
    constructorFlag = false;
    setKind(AST_ASSIGNMENT);
}

AssignmentExpression::AssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    constructorFlag = false;
    setKind(AST_ASSIGNMENT);
}

AssignmentExpression::AssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    constructorFlag = false;
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

bool AssignmentExpression::getConstructorFlag() const
{
    return constructorFlag;
}

void AssignmentExpression::setConstructorFlag(bool value)
{
    constructorFlag = value;
}
