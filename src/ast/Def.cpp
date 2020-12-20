#include <iostream>
#include <sstream>

#include "ast/Def.h"

using namespace hdc;

Def::Def() {
    klass = nullptr;
    file = nullptr;
    return_type = nullptr;
    statements = nullptr;
    symbolTable = nullptr;
    localVarNameCounter = 0;
    selfType = nullptr;
    id = 0;
    globald = 0;

    setKind(AST_DEF);
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

std::string Def::getUniqueCppName() {
    std::stringstream s;

    if (isMethod()) {
        s << "m" << id << "_" << getName();
    } else {
        s << "d" << id << "_" << getName();
    }

    return s.str();
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

Type *Def::getSelfType() {
    return selfType;
}

CompoundStatement* Def::getStatements() {
    return statements;
}

int Def::getLine() {
    return name.getLine();
}

int Def::getColumn() {
    return name.getColumn();
}

Class *Def::getClass() {
    return klass;
}

bool Def::isMethod() {
    return klass != nullptr;
}

bool Def::sameSignature(Def* other) {
    Type* t1;
    Type* t2;

    if (klass == other->klass) {
        if (getName().compare(other->getName()) == 0) {
            int n = n_parameters();

            if (n == other->n_parameters()) {
                for (int i = 0; i < n; ++i) {
                    t1 = getParameter(i)->getType();
                    t2 = other->getParameter(i)->getType();

                    if (!t1->equals(t2)) {
                        return false;
                    }
                }

                return true;
            }
        }
    }

    return false;
}

void Def::addParameter(hdc::Token& name, Type* type) {
    Parameter* param;

    param = new Parameter(name, type);
    param->setLocalName(localVarNameCounter++);
    parameters.push_back(param);
}

int Def::n_parameters() {
    return parameters.size();
}

int Def::n_local_variables() {
    return localVariables.size();
}

void Def::addLocalVariable(LocalVariable* variable) {
    variable->setLocalName(localVarNameCounter++);
    localVariables.push_back(variable);
}

void Def::accept(Visitor* visitor) {
    visitor->visit(this);
}

int Def::getId() const {
    return id;
}

void Def::setId(int value) {
    id = value;
}

int Def::getGlobalId() const {
    return globald;
}

void Def::setGlobalId(int value) {
    globald = value;
}

SymbolTable* Def::getSymbolTable() const {
    return symbolTable;
}

void Def::setSymbolTable(SymbolTable* value) {
    symbolTable = value;
}
