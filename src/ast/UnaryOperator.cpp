#include "ast/UnaryOperator.h"

using namespace hdc;

/* Constructors */
UnaryOperator::UnaryOperator() {
    expression = nullptr;
}

UnaryOperator::UnaryOperator(Expression* expression) {
    this->expression = expression;
    expression->setParentNode(this);
}

UnaryOperator::UnaryOperator(Token& oper, Expression* expression) {
    this->oper = oper;
    this->expression = expression;
    expression->setParentNode(this);
}


/* Destructors */
UnaryOperator::~UnaryOperator() {
    delete expression;
}

/* Setters */
void UnaryOperator::setExpression(Expression* expression) {
    if (this->expression != nullptr) {
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

