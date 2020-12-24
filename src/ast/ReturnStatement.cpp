#include "ast/ReturnStatement.h"

using namespace hdc;

ReturnStatement::ReturnStatement() {
    expression = nullptr;
    setKind(AST_RETURN);
}

ReturnStatement::ReturnStatement(Token& token) {
    this->token = token;
    this->expression = nullptr;
    setKind(AST_RETURN);
}

ReturnStatement::ReturnStatement(Token& token, Expression* expression) {
    this->token = token;
    this->expression = expression;
    setKind(AST_RETURN);
    expression->setParentNode(this);
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

void ReturnStatement::addLiveVariable(Variable *var) {
    liveVariables.push_back(var);
}

void ReturnStatement::accept(Visitor* visitor) {
    visitor->visit(this);
}

std::vector<Variable *> ReturnStatement::getLiveVariables() const
{
    return liveVariables;
}

void ReturnStatement::setLiveVariables(const std::vector<Variable *> &value)
{
    liveVariables = value;
}
