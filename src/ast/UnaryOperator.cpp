#include "ast/UnaryOperator.h"

using namespace hdc;

/* Constructors */
UnaryOperator::UnaryOperator() {
    expression = NULL;
}

UnaryOperator::UnaryOperator(Expression* expression) {
    this->expression = expression;
}

UnaryOperator::UnaryOperator(Token& oper, Expression* expression) {
    this->oper = oper;
    this->expression = expression;
}


/* Destructors */
UnaryOperator::~UnaryOperator() {
    delete expression;
}

/* Setters */
void UnaryOperator::setExpression(Expression* expression) {
    if (this->expression != NULL) {
        delete this->expression;
    }

    this->expression = expression;
}

/* Getters */
Expression* UnaryOperator::getExpression() {
    return expression;
}

/* Visitors */
void UnaryOperator::accept(Visitor* visitor) {
    visitor->visit(this);
}

