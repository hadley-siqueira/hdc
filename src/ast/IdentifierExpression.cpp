#include "ast/IdentifierExpression.h"

using namespace hdc;

IdentifierExpression::IdentifierExpression() {
    this->alias_flag = false;
    this->setKind(AST_IDENTIFIER);
    this->symbol = nullptr;
}


IdentifierExpression::IdentifierExpression(Token& name) {
    this->name = name;
    this->alias_flag = false;
    this->setKind(AST_IDENTIFIER);
    this->symbol = nullptr;
}


IdentifierExpression::IdentifierExpression(Token& alias, Token& name) {
    this->name = name;
    this->alias = alias;
    this->alias_flag = true;
    this->setKind(AST_IDENTIFIER);
    this->symbol = nullptr;
}

IdentifierExpression::IdentifierExpression(IdentifierExpression* id) {
    this->name = id->name;
    this->alias = id->alias;
    this->alias_flag = id->alias_flag;
    this->setKind(AST_IDENTIFIER);
    this->symbol = id->symbol;
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

Symbol* IdentifierExpression::getSymbol() const {
    return symbol;
}

void IdentifierExpression::setSymbol(Symbol* value) {
    symbol = value;
}
