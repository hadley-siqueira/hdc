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

    for (int i = 0; i < localVariables.size(); ++i) {
        delete localVariables[i];
    }

    delete return_type;
    delete statements;
    delete symbolTable;
}

void Def::setName(hdc::Token name) {
    this->name = name;
}

void Def::setClass(hdc::Class* klass) {
    this->klass = klass;
}

void Def::setFile(hdc::SourceFile* file) {
    this->file = file;
}

void Def::setReturnType(Type* type) {
    if (this->return_type != nullptr) {
        delete this->return_type;
    }

    this->return_type = type;
}

void Def::setStatements(CompoundStatement* statements) {
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
    }

    return nullptr;
}

LocalVariable*Def::getLocalVariable(int i) {
    if (i < localVariables.size()) {
        return localVariables[i];
    }

    return nullptr;
}

Type* Def::getReturnType() {
    return return_type;
}

CompoundStatement* Def::getStatements() {
    return statements;
}


#include <iostream>

void Def::addParameter(hdc::Token& name, Type* type) {
    parameters.push_back(new Parameter(name, type));
}

int Def::n_parameters() {
    return parameters.size();
}

int Def::n_local_variables() {
    return localVariables.size();
}

void Def::addLocalVariable(LocalVariable* variable) {
    localVariables.push_back(variable);
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
