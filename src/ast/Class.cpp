#include "ast/Class.h"

using namespace hdc;

/* Constructors */
Class::Class() {
    parent = NULL;
    file = NULL;
}

/* Destructors */
Class::~Class() {
    for (int i = 0; i < methods.size(); ++i) {
        delete methods[i];
    }

    delete parent;
}

/* Setters */
void Class::setName(Token& token) {
    name = token;
}

void Class::setParent(IdentifierExpression* parent) {
    if (this->parent != NULL) {
        delete this->parent;
    }

    this->parent = parent;
}

/* Getters */
std::string Class::getName() {
    return name.getLexem();
}

IdentifierExpression* Class::getParent() {
    return parent;
}

Def* Class::getMethod(int i) {
    if (i < methods.size()) {
        return methods[i];
    }

    return NULL;
}

/* Predicates */
bool Class::hasParent() {
    return parent != NULL;
}

int Class::n_methods() {
    return methods.size();
}

void Class::addMethod(Def* def) {
    methods.push_back(def);
    def->setClass(this);
    def->setFile(this->file);
}

/* Visitors */
void Class::accept(Visitor* visitor) {
    visitor->visit(this);
}
