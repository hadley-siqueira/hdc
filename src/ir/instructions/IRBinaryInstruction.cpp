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
