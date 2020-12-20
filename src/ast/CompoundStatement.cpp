#include "ast/CompoundStatement.h"

using namespace hdc;

CompoundStatement::CompoundStatement() {
    setKind(AST_COMPOUND_STATEMENT);
}

CompoundStatement::~CompoundStatement() {
    for (int i = 0; i < statements.size(); ++i) {
        delete statements[i];
    }
}


int CompoundStatement::n_statements() {
    return statements.size();
}

Statement* CompoundStatement::getStatement(int i) {
    if (i < n_statements()) {
        return statements[i];
    } else {
        return nullptr;
    }
}

void CompoundStatement::addStatement(Statement* statement) {
    statements.push_back(statement);
}

void CompoundStatement::accept(Visitor* visitor) {
    visitor->visit(this);
}
