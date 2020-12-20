#include "ast/ArrayExpression.h"

using namespace hdc;

ArrayExpression::ArrayExpression() {
    setKind(AST_ARRAY_EXPRESSION);
}

ArrayExpression::~ArrayExpression() {
    for (int i = 0; i < expressions.size(); ++i) {
        delete expressions[i];
    }
}

void ArrayExpression::addExpression(Expression* expression) {
    expressions.push_back(expression);
}

int ArrayExpression::n_expressions() {
    return expressions.size();
}

Expression* ArrayExpression::getExpression(int i) {
    if (i < expressions.size()) {
        return expressions[i];
    }

    return nullptr;
}

void ArrayExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}


