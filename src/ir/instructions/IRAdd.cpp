#include "ir/instructions/IRAdd.h"

using namespace hdc;

IRAdd::IRAdd(IRValue *dst, IRValue *src1, IRValue *src2) {
    this->dst = dst;
    this->src1 = src1;
    this->src2 = src2;
}

IRValue *IRAdd::getDestination() {
    return dst;
}

IRValue *IRAdd::getSource1() {
    return src1;
}

IRValue *IRAdd::getSource2() {
    return src2;
}

void IRAdd::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
