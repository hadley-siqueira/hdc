#include "ast/AddressOfExpression.h"

using namespace hdc;

/* Constructors */
AddressOfExpression::AddressOfExpression() {
    /* Empty */
}

AddressOfExpression::AddressOfExpression(Expression* expression) : UnaryOperator(expression) {
    /* Empty */
}

AddressOfExpression::AddressOfExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    /* Empty */
}

/* Destructors */
AddressOfExpression::~AddressOfExpression() {
    /* Empty */
}

/* Visitors */
void AddressOfExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
