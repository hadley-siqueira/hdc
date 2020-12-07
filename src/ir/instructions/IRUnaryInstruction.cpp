#include "ir/instructions/IRUnaryInstruction.h"

using namespace hdc;

IRValue *IRUnaryInstruction::getDestination() {
    return dst;
}

IRValue *IRUnaryInstruction::getSource() {
    return src;
}

void IRUnaryInstruction::setDestination(IRValue *dst) {
    this->dst = dst;
    dst->setCreatedBy(this);
}

void IRUnaryInstruction::setSource(IRValue *src) {
    this->src = src;
    src->makeUsedBy(this);
}
