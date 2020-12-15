#include <sstream>

#include "ast/Class.h"

using namespace hdc;

/* Constructors */
Class::Class() {
    parent = nullptr;
    file = nullptr;
    selfType = nullptr;
    classVariableCounter = 0;
    methodCounter = 0;
    id = 0;
    globalId = 0;
}

/* Destructors */
Class::~Class() {
    for (int i = 0; i < methods.size(); ++i) {
        delete methods[i];
    }

    for (int i = 0; i < variables.size(); ++i) {
        delete variables[i];
    }

    delete symbolTable;
    delete parent;
    delete selfType;
}

/* Setters */
void Class::setName(Token& token) {
    name = token;
}

void Class::setParent(IdentifierExpression* parent) {
    if (this->parent != nullptr) {
        delete this->parent;
    }

    this->parent = parent;
}

/* Getters */
std::string Class::getName() {
    return name.getLexem();
}

std::string Class::getUniqueCppName() {
    std::stringstream s;

    s << "c" << id << '_' << getName();
    return s.str();
}

IdentifierExpression* Class::getParent() {
    return parent;
}

Def* Class::getMethod(int i) {
    if (i < methods.size()) {
        return methods[i];
    }

    return nullptr;
}

ClassVariable*Class::getVariable(int i) {
    if (i < variables.size()) {
        return variables[i];
    }

    return nullptr;
}

int Class::getLine() {
    return name.getLine();
}

int Class::getColumn() {
    return name.getColumn();
}

ClassVariable *Class::getVariable(std::string name) {
    std::string n;

    for (int i = 0; i < variables.size(); ++i) {
        n = variables[i]->getName();

        if (name.compare(n) == 0) {
            return variables[i];
        }
    }

    return nullptr;
}

void Class::setSourceFile(SourceFile *s) {
    file = s;
}

/* Predicates */
bool Class::hasParent() {
    return parent != nullptr;
}

int Class::n_methods() {
    return methods.size();
}

int Class::n_variables() {
    return variables.size();
}

void Class::addMethod(Def* def) {
    methods.push_back(def);
    def->setClass(this);
    def->setFile(this->file);
    def->setId(methodCounter++);
    //def->setGlobalID(0);
}

void Class::addVariable(ClassVariable* variable) {
    variable->setLocalName(classVariableCounter++);
    variables.push_back(variable);
}

/* Visitors */
void Class::accept(Visitor* visitor) {
    visitor->visit(this);
}

SymbolTable* Class::getSymbolTable() const {
    return symbolTable;
}

void Class::setSymbolTable(SymbolTable* value) {
    symbolTable = value;
}

int Class::getId() const {
    return id;
}

void Class::setId(int value) {
    id = value;
}

int Class::getGlobalId() const {
    return globalId;
}

void Class::setGlobalId(int value) {
    globalId = value;
}

Type *Class::getSelfType() {
    if (selfType == nullptr) {
        selfType = new NamedType(new IdentifierExpression(name));
        selfType->setDescriptor(this);
    }

    return selfType;
}
