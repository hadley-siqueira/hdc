#include "ast/LiteralBoolExpression.h"

using namespace hdc;

/* Constructors */
LiteralBoolExpression::LiteralBoolExpression() {
    setKind(AST_LITERAL_BOOL);
}

LiteralBoolExpression::LiteralBoolExpression(Token token) {
    this->token = token;
    setKind(AST_LITERAL_BOOL);
}

/* Destructors */
LiteralBoolExpression::~LiteralBoolExpression() {

}

/* Visitors */
void LiteralBoolExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
