#include "ir/values/IRConstant.h"

using namespace hdc;

IRConstant::IRConstant(std::string value) {
    this->value = value;
}

std::string IRConstant::getValue() {
    return value;
}

void IRConstant::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
