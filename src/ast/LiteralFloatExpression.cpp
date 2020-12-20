#include "ast/LiteralFloatExpression.h"

using namespace hdc;

/* Constructors */
LiteralFloatExpression::LiteralFloatExpression() {
    setKind(AST_LITERAL_FLOAT);
}

LiteralFloatExpression::LiteralFloatExpression(Token token) {
    this->token = token;
    setKind(AST_LITERAL_FLOAT);
}

/* Destructors */
LiteralFloatExpression::~LiteralFloatExpression() {

}

/* Visitors */
void LiteralFloatExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
