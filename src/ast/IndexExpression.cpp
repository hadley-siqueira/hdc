#include "ast/IndexExpression.h"

using namespace hdc;

/* Constructors */
IndexExpression::IndexExpression() {
    /* Empty */
}

IndexExpression::IndexExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    /* Empty */
}

IndexExpression::IndexExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    /* Empty */
}

/* Destructors */
IndexExpression::~IndexExpression() {
    /* Empty */
}

/* Visitors */
void IndexExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
