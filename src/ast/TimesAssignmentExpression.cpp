#include "ast/TimesAssignmentExpression.h"

using namespace hdc;

/* Constructors */
TimesAssignmentExpression::TimesAssignmentExpression() {
    setKind(AST_TIMES_ASSIGNMENT);
}

TimesAssignmentExpression::TimesAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_TIMES_ASSIGNMENT);
}

TimesAssignmentExpression::TimesAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_TIMES_ASSIGNMENT);
}

/* Destructors */
TimesAssignmentExpression::~TimesAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void TimesAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
