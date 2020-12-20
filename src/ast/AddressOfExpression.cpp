#include "ast/AddressOfExpression.h"

using namespace hdc;

/* Constructors */
AddressOfExpression::AddressOfExpression() {
    setKind(AST_ADDRESS_OF);
}

AddressOfExpression::AddressOfExpression(Expression* expression) : UnaryOperator(expression) {
    setKind(AST_ADDRESS_OF);
}

AddressOfExpression::AddressOfExpression(Token& oper, Expression* expression) : UnaryOperator(oper, expression) {
    setKind(AST_ADDRESS_OF);
}

/* Destructors */
AddressOfExpression::~AddressOfExpression() {
    /* Empty */
}

/* Visitors */
void AddressOfExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
