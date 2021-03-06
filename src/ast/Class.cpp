#include <sstream>

#include "ast/Class.h"

using namespace hdc;

/* Constructors */
Class::Class() {
    classVariableCounter = 0;
    methodCounter = 0;
    id = 0;
    globalId = 0;

    superClass = nullptr;
    file = nullptr;
    selfType = nullptr;
    destructor = nullptr;
    symbolTable = nullptr;

    setKind(AST_CLASS);
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
    delete superClass;
    delete selfType;
}

/* Setters */
void Class::setName(Token& token) {
    name = token;
}

void Class::setSuperClass(NamedType *parent) {
    if (this->superClass != nullptr) {
        delete this->superClass;
    }

    this->superClass = parent;
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

Def* Class::getMethod(int i) {
    if (i < methods.size()) {
        return methods[i];
    }

    return nullptr;
}

Def* Class::getConstructor(int i) {
    if (i < constructors.size()) {
        return constructors[i];
    }

    return nullptr;
}

Def* Class::getDestructor() {
    return destructor;
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
bool Class::hasSuperClass() {
    return superClass != nullptr;
}

int Class::n_methods() {
    return methods.size();
}

int Class::n_variables() {
    return variables.size();
}

int Class::n_constructors() {
    return constructors.size();
}

void Class::addMethod(Def* def) {
    methods.push_back(def);
    def->setClass(this);
    def->setFile(this->file);
    def->setId(methodCounter++);
    //def->setGlobalID(0);

    if (def->getName().compare("init") == 0) {
        constructors.push_back(def);
    } else if (def->getName().compare("destroy") == 0) {
        destructor = def;
    }
}

void Class::addVariable(ClassVariable* variable) {
    variable->setLocalName(classVariableCounter++);
    variables.push_back(variable);
}

/* Visitors */
void Class::accept(Visitor* visitor) {
    visitor->visit(this);
}

NamedType *Class::getSuperClass() const {
    return superClass;
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
    }

    return selfType;
}
