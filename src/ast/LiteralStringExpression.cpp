#include "ast/LiteralStringExpression.h"

using namespace hdc;

/* Constructors */
LiteralStringExpression::LiteralStringExpression() {
    setKind(AST_LITERAL_STRING);
}

LiteralStringExpression::LiteralStringExpression(Token token) {
    this->token = token;
    setKind(AST_LITERAL_STRING);
}

/* Destructors */
LiteralStringExpression::~LiteralStringExpression() {

}

/* Visitors */
void LiteralStringExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
