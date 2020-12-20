#include "ast/LiteralIntegerExpression.h"

using namespace hdc;

/* Constructors */
LiteralIntegerExpression::LiteralIntegerExpression() {
    setKind(AST_LITERAL_INTEGER);
}

LiteralIntegerExpression::LiteralIntegerExpression(Token token) {
    this->token = token;
    setKind(AST_LITERAL_INTEGER);
}

/* Destructors */
LiteralIntegerExpression::~LiteralIntegerExpression() {

}

/* Visitors */
void LiteralIntegerExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
