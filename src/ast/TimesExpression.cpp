#include "ast/TimesExpression.h"

using namespace hdc;

/* Constructors */
TimesExpression::TimesExpression() {
    /* Empty */
}

TimesExpression::TimesExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

TimesExpression::TimesExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
TimesExpression::~TimesExpression() {
    /* Empty */
}

/* Visitors */
void TimesExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
