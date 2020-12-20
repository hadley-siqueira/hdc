#include "ast/ElifStatement.h"

using namespace hdc;

hdc::ElifStatement::ElifStatement(hdc::Expression* expression, hdc::CompoundStatement* statements) {
    this->expression = expression;
    this->statements = statements;
    this->elifStatement = nullptr;
    this->elseStatement = nullptr;
    this->symbolTable = nullptr;
    setKind(AST_ELIF);
}

hdc::ElifStatement::ElifStatement(hdc::Expression* expression, hdc::CompoundStatement* statements, hdc::ElifStatement* elifStatement) {
    this->expression = expression;
    this->statements = statements;
    this->elifStatement = elifStatement;
    this->elseStatement = nullptr;
    this->symbolTable = nullptr;
    setKind(AST_ELIF);
}

hdc::ElifStatement::ElifStatement(hdc::Expression* expression, hdc::CompoundStatement* statements, hdc::ElseStatement* elseStatement) {
    this->expression = expression;
    this->statements = statements;
    this->elifStatement = nullptr;
    this->elseStatement = elseStatement;
    this->symbolTable = nullptr;
    setKind(AST_ELIF);
}

ElifStatement::~ElifStatement() {
    delete expression;
    delete statements;
    delete elifStatement;
    delete elseStatement;
    delete symbolTable;
}

ElifStatement* ElifStatement::getElifStatement() const {
    return elifStatement;
}

void ElifStatement::setElifStatement(ElifStatement* value) {
    elifStatement = value;
}

ElseStatement* ElifStatement::getElseStatement() const {
    return elseStatement;
}

void ElifStatement::setElseStatement(ElseStatement* value) {
    elseStatement = value;
}

CompoundStatement* ElifStatement::getStatements() const {
    return statements;
}

void ElifStatement::setStatements(CompoundStatement* value) {
    statements = value;
}

Expression* ElifStatement::getExpression() const {
    return expression;
}

void ElifStatement::setExpression(Expression* value) {
    expression = value;
}

void ElifStatement::accept(Visitor* visitor) {
    visitor->visit(this);
}

SymbolTable* ElifStatement::getSymbolTable() const
{
    return symbolTable;
}

void ElifStatement::setSymbolTable(SymbolTable* value)
{
    symbolTable = value;
}
