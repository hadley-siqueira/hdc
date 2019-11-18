#include "ast/IdentifierExpression.h"

using namespace hdc;

IdentifierExpression::IdentifierExpression() {
    this->alias_flag = false;
    this->setKind(AST_IDENTIFIER);
}


IdentifierExpression::IdentifierExpression(Token& name) {
    this->name = name;
    this->alias_flag = false;
    this->setKind(AST_IDENTIFIER);
}


IdentifierExpression::IdentifierExpression(Token& alias, Token& name) {
    this->name = name;
    this->alias = alias;
    this->alias_flag = true;
    this->setKind(AST_IDENTIFIER);
}


IdentifierExpression::~IdentifierExpression() {
    /* empty */
}

/* Predicates */
bool IdentifierExpression::hasAlias() {
    return alias_flag;
}

/* Getters */
std::string IdentifierExpression::getAlias() {
    return alias.getLexem();
}

std::string IdentifierExpression::getName() {
    return name.getLexem();
}

Token& IdentifierExpression::getNameAsToken() {
    return name;
}

/* Visitors */
void IdentifierExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
