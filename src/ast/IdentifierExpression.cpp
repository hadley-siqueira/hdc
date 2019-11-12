#include "ast/IdentifierExpression.h"

using namespace hdc;

IdentifierExpression::IdentifierExpression() {
    this->alias_flag = false;
}


IdentifierExpression::IdentifierExpression(Token& name) {
    this->name = name;
    this->alias_flag = false;
}


IdentifierExpression::IdentifierExpression(Token& alias, Token& name) {
    this->name = name;
    this->alias = alias;
    this->alias_flag = true;
}


IdentifierExpression::~IdentifierExpression() {
    /* empty */
}

/* Predicates */
bool IdentifierExpression::has_alias() {
    return alias_flag;
}

/* Getters */
std::string IdentifierExpression::get_alias() {
    return alias.getLexem();
}

std::string IdentifierExpression::get_name() {
    return name.getLexem();
}

/* Visitors */
void IdentifierExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
