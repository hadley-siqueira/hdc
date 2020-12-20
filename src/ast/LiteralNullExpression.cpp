#include "ast/LiteralNullExpression.h"

using namespace hdc;

/* Constructors */
LiteralNullExpression::LiteralNullExpression() {
    setKind(AST_LITERAL_NULL);
}

LiteralNullExpression::LiteralNullExpression(Token token) {
    this->token = token;
    setKind(AST_LITERAL_NULL);
}

/* Destructors */
LiteralNullExpression::~LiteralNullExpression() {

}

/* Visitors */
void LiteralNullExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
