#include "ast/ForStatement.h"

using namespace hdc;

ForStatement::ForStatement(Expression* e1, Expression* e2, Expression* e3, CompoundStatement* statements) {
    this->e1 = e1;
    this->e2 = e2;
    this->e3 = e3;
    this->statements = statements;
    setKind(AST_FOR);
}

ForStatement::~ForStatement() {
    delete e1;
    delete e2;
    delete e3;
    delete statements;
    setKind(AST_FOR);
}

Expression* ForStatement::getE1() const {
    return e1;
}

void ForStatement::setE1(Expression* value) {
    e1 = value;
}

Expression* ForStatement::getE2() const {
    return e2;
}

void ForStatement::setE2(Expression* value) {
    e2 = value;
}

Expression* ForStatement::getE3() const {
    return e3;
}

void ForStatement::setE3(Expression* value) {
    e3 = value;
}

CompoundStatement* ForStatement::getStatements() const {
    return statements;
}

void ForStatement::setStatements(CompoundStatement* value) {
    statements = value;
}

void ForStatement::accept(Visitor* visitor) {
    visitor->visit(this);
}
