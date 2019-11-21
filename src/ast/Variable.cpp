#include "ast/Variable.h"

using namespace hdc;

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
