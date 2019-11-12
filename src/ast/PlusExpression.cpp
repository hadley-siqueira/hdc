#include "ast/PlusExpression.h"

using namespace hdc;

/* Constructors */
PlusExpression::PlusExpression() {
    /* Empty */
}

PlusExpression::PlusExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

PlusExpression::PlusExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
PlusExpression::~PlusExpression() {
    /* Empty */
}

/* Visitors */
void PlusExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
