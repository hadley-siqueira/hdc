#include "ast/Def.h"

using namespace hdc;

Def::Def() {
    klass = nullptr;
    file = nullptr;
    return_type = nullptr;
    statements = nullptr;
    symbolTable = nullptr;
}


Def::~Def() {
    for (int i = 0; i < parameters.size(); ++i) {
        delete parameters[i];
    }

    delete return_type;
    delete statements;
    delete symbolTable;
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
    if (this->return_type != nullptr) {
        delete this->return_type;
    }

    this->return_type = type;
}


void Def::set_statements(CompoundStatement* statements) {
    if (this->statements != nullptr) {
        delete this->statements;
    }

    this->statements = statements;
}


std::string Def::getName() {
    return name.getLexem();
}


Parameter* Def::getParameter(int i) {
    if (i < parameters.size()) {
        return parameters[i];
    } else {
        return nullptr;
    }
}


Type* Def::getReturnType() {
    return return_type;
}


CompoundStatement* Def::getStatements() {
    return statements;
}


void Def::addParameter(hdc::Token& name, Type* type) {
    parameters.push_back(new Parameter(name, type));
}


int Def::n_parameters() {
    return parameters.size();
}

void Def::accept(Visitor* visitor) {
    visitor->visit(this);
}

SymbolTable* Def::getSymbolTable() const {
    return symbolTable;
}

void Def::setSymbolTable(SymbolTable* value) {
    symbolTable = value;
}
