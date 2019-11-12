#include "ast/TimesAssignmentExpression.h"

using namespace hdc;

/* Constructors */
TimesAssignmentExpression::TimesAssignmentExpression() {
    /* Empty */
}

TimesAssignmentExpression::TimesAssignmentExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

TimesAssignmentExpression::TimesAssignmentExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
TimesAssignmentExpression::~TimesAssignmentExpression() {
    /* Empty */
}

/* Visitors */
void TimesAssignmentExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
