#include "ast/ReturnStatement.h"

using namespace hdc;

ReturnStatement::ReturnStatement() {
    expression = nullptr;
}

ReturnStatement::ReturnStatement(Token& token) {
    this->token = token;
    this->expression = nullptr;
}

ReturnStatement::ReturnStatement(Token& token, Expression* expression) {
    this->token = token;
    this->expression = expression;
}

ReturnStatement::~ReturnStatement() {
    delete expression;
}

Expression* ReturnStatement::getExpression() const {
    return expression;
}

void ReturnStatement::setExpression(Expression* value) {
    expression = value;
}

void ReturnStatement::accept(Visitor* visitor) {
    visitor->visit(this);
}
