#include "ir/instructions/IRLoadConstant.h"

using namespace hdc;

IRLoadConstant::IRLoadConstant(IRValue *dst, IRValue *src) {
    this->dst = dst;
    this->src = src;
}

void IRLoadConstant::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
