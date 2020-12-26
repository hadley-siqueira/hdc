#include "ast/statements/VariableDeclarationStatement.h"

using namespace hdc;

VariableDeclarationStatement::VariableDeclarationStatement(IdentifierExpression* name, Type *type, Expression *expression) {
    this->name = name;
    this->type = type;
    this->expression = expression;
    setKind(AST_VARIABLE_DECLARATION);
}

VariableDeclarationStatement::~VariableDeclarationStatement() {
    delete name;
    delete type;
    delete expression;
}

void VariableDeclarationStatement::accept(Visitor *visitor) {
    visitor->visit(this);
}

IdentifierExpression *VariableDeclarationStatement::getName() const {
    return name;
}

void VariableDeclarationStatement::setName(IdentifierExpression *value) {
    name = value;
}

Type *VariableDeclarationStatement::getType() const {
    return type;
}

void VariableDeclarationStatement::setType(Type *value) {
    type = value;
}

Expression *VariableDeclarationStatement::getExpression() const {
    return expression;
}

void VariableDeclarationStatement::setExpression(Expression *value) {
    expression = value;
}
