#include "ast/operators/binary/LogicalOrExpression.h"

using namespace hdc;

/* Constructors */
LogicalOrExpression::LogicalOrExpression() {
    setKind(AST_LOGICAL_OR);
}

LogicalOrExpression::LogicalOrExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_LOGICAL_OR);
}

LogicalOrExpression::LogicalOrExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_LOGICAL_OR);
}

/* Destructors */
LogicalOrExpression::~LogicalOrExpression() {
    /* Empty */
}

/* Visitors */
void LogicalOrExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
