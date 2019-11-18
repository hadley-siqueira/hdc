#include "ast/IfStatement.h"

using namespace hdc;

IfStatement::IfStatement(Expression* expression, CompoundStatement* statements) {
    this->expression = expression;
    this->statements = statements;
    this->elifStatement = nullptr;
    this->elseStatement = nullptr;
}

IfStatement::IfStatement(Expression* expression, CompoundStatement* statements, ElifStatement* elifStatement) {
    this->expression = expression;
    this->statements = statements;
    this->elifStatement = elifStatement;
    this->elseStatement = nullptr;
}

IfStatement::IfStatement(Expression* expression, CompoundStatement* statements, ElseStatement* elseStatement) {
    this->expression = expression;
    this->statements = statements;
    this->elifStatement = nullptr;
    this->elseStatement = elseStatement;
}

IfStatement::~IfStatement() {
    delete expression;
    delete statements;
    delete elifStatement;
    delete elseStatement;
}

ElifStatement* IfStatement::getElifStatement() const {
    return elifStatement;
}

void IfStatement::setElifStatement(ElifStatement* value) {
    elifStatement = value;
}

ElseStatement* IfStatement::getElseStatement() const {
    return elseStatement;
}

void IfStatement::setElseStatement(ElseStatement* value) {
    elseStatement = value;
}

CompoundStatement* IfStatement::getStatements() const {
    return statements;
}

void IfStatement::setStatements(CompoundStatement* value) {
    statements = value;
}

Expression* IfStatement::getExpression() const
{
    return expression;
}

void IfStatement::setExpression(Expression* value)
{
    expression = value;
}

void IfStatement::accept(Visitor* visitor) {
    visitor->visit(this);
}

SymbolTable* IfStatement::getSymbolTable() const
{
    return symbolTable;
}

void IfStatement::setSymbolTable(SymbolTable* value)
{
    symbolTable = value;
}
