#include "ast/LogicalNotExpression.h"

using namespace hdc;

/* Constructors */
LogicalNotExpression::LogicalNotExpression() {
    setKind(AST_LOGICAL_NOT);
}

LogicalNotExpression::LogicalNotExpression(Expression* expression) : UnaryOperator(expression) {
    setKind(AST_LOGICAL_NOT);
}

LogicalNotExpression::LogicalNotExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    setKind(AST_LOGICAL_NOT);
}

/* Destructors */
LogicalNotExpression::~LogicalNotExpression() {
    /* Empty */
}

/* Visitors */
void LogicalNotExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
