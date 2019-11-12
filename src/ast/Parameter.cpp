#include "ast/Parameter.h"

using namespace hdc;

Parameter::Parameter() {
    this->type = NULL;
}


Parameter::Parameter(Token& name, Type* type) {
    this->name = name;
    this->type = type;
}


Parameter::~Parameter() {
    if (type != NULL) {
        delete type;
    }
}


void Parameter::set_name(Token& name) {
    this->name = name;
}


void Parameter::set_type(Type* type) {
    if (this->type != NULL) {
        delete this->type;
    }

    this->type = type;
}


std::string Parameter::get_name() {
    return name.getLexem();
}


Type* Parameter::get_type() {
    return type;
}


void Parameter::accept(Visitor* visitor) {
    visitor->visit(this);
}
