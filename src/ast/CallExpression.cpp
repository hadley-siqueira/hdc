#include "ast/CallExpression.h"

using namespace hdc;

/* Constructors */
CallExpression::CallExpression() {
    expression = nullptr;
}

CallExpression::CallExpression(Expression* expression, std::vector<Expression*> arguments) {
    this->expression = expression;
    this->arguments = arguments;
}

CallExpression::CallExpression(Token& oper, Expression* expression, std::vector<Expression*> arguments) {
    this->oper = oper;
    this->expression = expression;
    this->arguments = arguments;
}

/* Destructors */
CallExpression::~CallExpression() {
    for (int i = 0; i < arguments.size(); ++i) {
        delete arguments[i];
    }

    delete expression;
}

/* Setters */
void CallExpression::setExpression(Expression* expression) {
    if (this->expression != nullptr) {
        delete this->expression;
    }

    this->expression = expression;
}

void CallExpression::setArguments(std::vector<Expression*> arguments) {
    for (int i = 0; i < this->arguments.size(); ++i) {
        delete this->arguments[i];
    }

    this->arguments = arguments; 
}

/* Getters */
Expression* CallExpression::getExpression() {
    return expression;
}

std::vector<Expression*>& CallExpression::getArguments() {
    return arguments;
}

Expression* CallExpression::getArgument(int i) {
    return arguments[i];
}

int CallExpression::n_arguments() {
    return arguments.size();
}

/* Actions */
void CallExpression::addArgument(Expression* expression) {
    arguments.push_back(expression);
}

/* Visitors */
void CallExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}

