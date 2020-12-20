#include "ast/TimesExpression.h"

using namespace hdc;

/* Constructors */
TimesExpression::TimesExpression() {
    setKind(AST_TIMES);
}

TimesExpression::TimesExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_TIMES);
}

TimesExpression::TimesExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_TIMES);
}

/* Destructors */
TimesExpression::~TimesExpression() {
    /* Empty */
}

/* Visitors */
void TimesExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
