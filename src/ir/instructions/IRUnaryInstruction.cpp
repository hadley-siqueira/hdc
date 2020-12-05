#include "ir/instructions/IRUnaryInstruction.h"

using namespace hdc;

IRValue *IRUnaryInstruction::getDestination() {
    return dst;
}

IRValue *IRUnaryInstruction::getSource() {
    return src;
}
