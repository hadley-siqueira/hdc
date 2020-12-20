#include "ast/LiteralDoubleExpression.h"

using namespace hdc;

/* Constructors */
LiteralDoubleExpression::LiteralDoubleExpression() {
    setKind(AST_LITERAL_DOUBLE);
}

LiteralDoubleExpression::LiteralDoubleExpression(Token token) {
    this->token = token;
    setKind(AST_LITERAL_DOUBLE);
}

/* Destructors */
LiteralDoubleExpression::~LiteralDoubleExpression() {

}

/* Visitors */
void LiteralDoubleExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
