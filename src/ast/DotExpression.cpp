#include "ast/DotExpression.h"

using namespace hdc;

/* Constructors */
DotExpression::DotExpression() {
    setKind(AST_DOT);
}

DotExpression::DotExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_DOT);
}

DotExpression::DotExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_DOT);
}

/* Destructors */
DotExpression::~DotExpression() {
    /* Empty */
}

/* Visitors */
void DotExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
