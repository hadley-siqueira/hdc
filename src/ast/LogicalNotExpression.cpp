#include "ast/LogicalNotExpression.h"

using namespace hdc;

/* Constructors */
LogicalNotExpression::LogicalNotExpression() {
    /* Empty */
}

LogicalNotExpression::LogicalNotExpression(Expression* expression) : UnaryOperator(expression) {
    /* Empty */
}

LogicalNotExpression::LogicalNotExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    /* Empty */
}

/* Destructors */
LogicalNotExpression::~LogicalNotExpression() {
    /* Empty */
}

/* Visitors */
void LogicalNotExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
