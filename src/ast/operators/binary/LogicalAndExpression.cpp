#include "ast/operators/binary/LogicalAndExpression.h"

using namespace hdc;

/* Constructors */
LogicalAndExpression::LogicalAndExpression() {
    setKind(AST_LOGICAL_AND);
}

LogicalAndExpression::LogicalAndExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_LOGICAL_AND);
}

LogicalAndExpression::LogicalAndExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_LOGICAL_AND);
}

/* Destructors */
LogicalAndExpression::~LogicalAndExpression() {
    /* Empty */
}

/* Visitors */
void LogicalAndExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
