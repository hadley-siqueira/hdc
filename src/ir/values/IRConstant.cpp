#include "ir/values/IRConstant.h"

using namespace hdc;

IRConstant::IRConstant(Token token) {
    this->token = token;
}

std::string IRConstant::getValue() {
    return token.getLexem();
}

void IRConstant::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
