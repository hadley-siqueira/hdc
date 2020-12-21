#include "ast/WhileStatement.h"

using namespace hdc;

WhileStatement::WhileStatement() {
    expression = nullptr;
    statements = nullptr;
    setKind(AST_WHILE);
}


WhileStatement::WhileStatement(Expression* expression, CompoundStatement* statements) {
    this->expression = expression;
    this->statements = statements;
    setKind(AST_WHILE);
    expression->setParentNode(this);
    statements->setParentNode(this);
}


WhileStatement::~WhileStatement() {
    if (expression != nullptr) {
        delete expression;
    }

    if (statements != nullptr) {
        delete statements;
    }

    delete symbolTable;
}

/* Getters */
Expression* WhileStatement::getExpression() {
    return expression;
}

CompoundStatement* WhileStatement::getStatements() {
    return statements;
}

/* Visitors */
void WhileStatement::accept(Visitor* visitor) {
    visitor->visit(this);
}

SymbolTable *WhileStatement::getSymbolTable() const {
    return symbolTable;
}

void WhileStatement::setSymbolTable(SymbolTable *value) {
    symbolTable = value;
}
