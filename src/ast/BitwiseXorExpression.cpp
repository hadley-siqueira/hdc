#include "ast/BitwiseXorExpression.h"

using namespace hdc;

/* Constructors */
BitwiseXorExpression::BitwiseXorExpression() {
    setKind(AST_BITWISE_XOR);
}

BitwiseXorExpression::BitwiseXorExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_BITWISE_XOR);
}

BitwiseXorExpression::BitwiseXorExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_BITWISE_XOR);
}

/* Destructors */
BitwiseXorExpression::~BitwiseXorExpression() {
    /* Empty */
}

/* Visitors */
void BitwiseXorExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
