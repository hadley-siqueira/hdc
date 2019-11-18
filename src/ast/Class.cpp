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
void Class::set_name(Token& token) {
    name = token;
}

void Class::set_parent(IdentifierExpression* parent) {
    if (this->parent != NULL) {
        delete this->parent;
    }

    this->parent = parent;
}

/* Getters */
std::string Class::get_name() {
    return name.getLexem();
}

IdentifierExpression* Class::get_parent() {
    return parent;
}

Def* Class::get_method(int i) {
    if (i < methods.size()) {
        return methods[i];
    }

    return NULL;
}

/* Predicates */
bool Class::has_parent() {
    return parent != NULL;
}

int Class::n_methods() {
    return methods.size();
}

void Class::add_method(Def* def) {
    methods.push_back(def);
    def->setClass(this);
    def->setFile(this->file);
}

/* Visitors */
void Class::accept(Visitor* visitor) {
    visitor->visit(this);
}
