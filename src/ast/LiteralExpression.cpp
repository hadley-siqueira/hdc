#include "ast/LiteralExpression.h"

using namespace hdc;

/* Constructors */
LiteralExpression::LiteralExpression() {

}

LiteralExpression::LiteralExpression(Token token) {
    this->token = token;
}

/* Destructors */
LiteralExpression::~LiteralExpression() {

}

/* Setters */
void LiteralExpression::set_token(Token token) {
    this->token = token;
}

/* Getters */
Token LiteralExpression::get_token() {
    return token;
}

/* Visitors */
void LiteralExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
