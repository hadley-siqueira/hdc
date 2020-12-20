#include "ast/ListExpression.h"

using namespace hdc;

ListExpression::ListExpression() {
    setKind(AST_LIST_EXPRESSION);
}

ListExpression::~ListExpression() {
    for (int i = 0; i < expressions.size(); ++i) {
        delete expressions[i];
    }
}

void ListExpression::addExpression(Expression* expression) {
    expressions.push_back(expression);
}

int ListExpression::n_expressions() {
    return expressions.size();
}

Expression* ListExpression::getExpression(int i) {
    if (i < expressions.size()) {
        return expressions[i];
    }

    return nullptr;
}

void ListExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}


