#include "ast/PlusExpression.h"

using namespace hdc;

/* Constructors */
PlusExpression::PlusExpression() {
    setKind(AST_PLUS);
}

PlusExpression::PlusExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_PLUS);
}

PlusExpression::PlusExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_PLUS);
}

/* Destructors */
PlusExpression::~PlusExpression() {
    /* Empty */
}

/* Visitors */
void PlusExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
