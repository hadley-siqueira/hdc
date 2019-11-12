#include "ast/Def.h"

using namespace hdc;

Def::Def() {
    klass = NULL;
    file = NULL;
    return_type = NULL;
    statements = NULL;
}


Def::~Def() {
    for (int i = 0; i < parameters.size(); ++i) {
        delete parameters[i];
    }

    delete return_type;
    delete statements;
}


void Def::set_name(hdc::Token name) {
    this->name = name;
}


void Def::set_class(hdc::Class* klass) {
    this->klass = klass;
}


void Def::set_file(hdc::SourceFile* file) {
    this->file = file;
}


void Def::set_return_type(Type* type) {
    if (this->return_type != NULL) {
        delete this->return_type;
    }

    this->return_type = type;
}


void Def::set_statements(CompoundStatement* statements) {
    if (this->statements != NULL) {
        delete this->statements;
    }

    this->statements = statements;
}


std::string Def::get_name() {
    return name.getLexem();
}


Parameter* Def::get_parameter(int i) {
    if (i < parameters.size()) {
        return parameters[i];
    } else {
        return NULL;
    }
}


Type* Def::get_return_type() {
    return return_type;
}


CompoundStatement* Def::get_statements() {
    return statements;
}


void Def::add_parameter(hdc::Token& name, Type* type) {
    parameters.push_back(new Parameter(name, type));
}


int Def::n_parameters() {
    return parameters.size();
}

void Def::accept(Visitor* visitor) {
    visitor->visit(this);
}
