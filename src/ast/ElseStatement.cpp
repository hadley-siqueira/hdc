#include "ast/ElseStatement.h"

using namespace hdc;

ElseStatement::ElseStatement(CompoundStatement* statements) {
    this->statements = statements;
    setKind(AST_ELSE);
}

ElseStatement::~ElseStatement() {
    delete statements;
    delete symbolTable;
}

CompoundStatement* ElseStatement::getStatements() {
    return statements;
}

void ElseStatement::setStatements(CompoundStatement* value) {
    statements = value;
}

void ElseStatement::accept(Visitor* visitor) {
    visitor->visit(this);
}

SymbolTable* ElseStatement::getSymbolTable() const
{
    return symbolTable;
}

void ElseStatement::setSymbolTable(SymbolTable* value)
{
    symbolTable = value;
}
