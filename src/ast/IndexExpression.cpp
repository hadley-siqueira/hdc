#include "ast/IndexExpression.h"

using namespace hdc;

/* Constructors */
IndexExpression::IndexExpression() {
    setKind(AST_INDEX);
}

IndexExpression::IndexExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_INDEX);
}

IndexExpression::IndexExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_INDEX);
}

/* Destructors */
IndexExpression::~IndexExpression() {
    /* Empty */
}

/* Visitors */
void IndexExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
