#include "ast/ForEachStatement.h"

using namespace hdc;

ForEachStatement::ForEachStatement(Expression* e1, Expression* e2, CompoundStatement* statements) {
    this->e1 = e1;
    this->e2 = e2;
    this->statements = statements;
    setKind(AST_FOREACH);

    if (e1 != nullptr) {
        e1->setParentNode(this);
    }

    if (e2 != nullptr) {
        e2->setParentNode(this);
    }

    if (statements != nullptr) {
        statements->setParentNode(this);
    }
}

ForEachStatement::~ForEachStatement() {
    delete e1;
    delete e2;
    delete statements;
}

Expression* ForEachStatement::getE1() const
{
    return e1;
}

void ForEachStatement::setE1(Expression* value)
{
    e1 = value;
}

Expression* ForEachStatement::getE2() const
{
    return e2;
}

void ForEachStatement::setE2(Expression* value)
{
    e2 = value;
}

CompoundStatement* ForEachStatement::getStatements() const
{
    return statements;
}

void ForEachStatement::setStatements(CompoundStatement* value)
{
    statements = value;
}

void ForEachStatement::accept(Visitor* visitor) {
    visitor->visit(this);
}
