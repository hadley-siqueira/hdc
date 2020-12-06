#include "ir/instructions/IRBinaryInstruction.h"

using namespace hdc;

IRValue *IRBinaryInstruction::getDestination() {
    return dst;
}

IRValue *IRBinaryInstruction::getSource1() {
    return src1;
}

IRValue *IRBinaryInstruction::getSource2() {
    return src2;
}

void IRBinaryInstruction::setDestination(IRValue *dst) {
    this->dst = dst;
    dst->setCreatedBy(this);
}

void IRBinaryInstruction::setSource1(IRValue *src) {
    this->src1 = src;
    src->makeUsedBy(this);
}

void IRBinaryInstruction::setSource2(IRValue *src) {
    this->src2 = src;
    src->makeUsedBy(this);
}
