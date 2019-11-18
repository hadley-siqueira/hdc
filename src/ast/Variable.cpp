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
