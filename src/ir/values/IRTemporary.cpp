#include "ir/values/IRTemporary.h"

using namespace hdc;

IRTemporary::IRTemporary(unsigned int value) {
    this->value = value;
}

unsigned int IRTemporary::getValue() {
    return value;
}

void IRTemporary::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
