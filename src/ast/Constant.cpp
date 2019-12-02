#include "ast/Constant.h"

using namespace hdc;

Type* Constant::getType() const {
    return type;
}

void Constant::setType(Type* value) {
    type = value;
}

int Constant::getOffset() const {
    return offset;
}

void Constant::setOffset(int value) {
    offset = value;
}

std::string hdc::Constant::getName() {
    return token.getLexem();
}

int Constant::getLocalName() const {
    return localName;
}

void Constant::setLocalName(int value) {
    localName = value;
}

unsigned long long Constant::getGlobalName() const {
    return globalName;
}

void Constant::setGlobalName(unsigned long long value) {
    globalName = value;
}

bool Constant::getIsConstant() const {
    return isConstant;
}

void Constant::setIsConstant(bool value) {
    isConstant = value;
}

int Constant::getLine() {
    return token.getLine();
}

int Constant::getColumn() {
    return token.getColumn();
}

Expression* Constant::getExpression() const
{
    return expression;
}

void Constant::setExpression(Expression* value)
{
    expression = value;
}
