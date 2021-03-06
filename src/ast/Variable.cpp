#include "ast/Variable.h"

using namespace hdc;

Variable::~Variable() {
    delete type;
}

Type* Variable::getType() const {
    return type;
}

void Variable::setType(Type* value) {
    type = value;
}

int Variable::getOffset() const {
    return offset;
}

void Variable::setOffset(int value) {
    offset = value;
}

std::string hdc::Variable::getName() {
    return token.getLexem();
}

std::string Variable::getUniqueCppName() {
    return std::string("");
}

int Variable::getLocalName() const {
    return localName;
}

void Variable::setLocalName(int value) {
    localName = value;
}

unsigned long long Variable::getGlobalName() const {
    return globalName;
}

void Variable::setGlobalName(unsigned long long value) {
    globalName = value;
}

bool Variable::getIsConstant() const {
    return isConstant;
}

void Variable::setIsConstant(bool value) {
    isConstant = value;
}

int Variable::getLine() {
    return token.getLine();
}

int Variable::getColumn() {
    return token.getColumn();
}
