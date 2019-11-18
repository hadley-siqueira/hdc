#include "ast/WhileStatement.h"

using namespace hdc;

WhileStatement::WhileStatement() {
    expression = NULL;
    statements = NULL;
}


WhileStatement::WhileStatement(Expression* expression, CompoundStatement* statements) {
    this->expression = expression;
    this->statements = statements;
}


WhileStatement::~WhileStatement() {
    if (expression != NULL) {
        delete expression;
    }

    if (statements != NULL) {
        delete statements;
    }
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
