#include "ast/LiteralCharExpression.h"

using namespace hdc;

/* Constructors */
LiteralCharExpression::LiteralCharExpression() {
    setKind(AST_LITERAL_CHAR);
}

LiteralCharExpression::LiteralCharExpression(Token token) {
    this->token = token;
    setKind(AST_LITERAL_CHAR);
}

/* Destructors */
LiteralCharExpression::~LiteralCharExpression() {

}

/* Visitors */
void LiteralCharExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
