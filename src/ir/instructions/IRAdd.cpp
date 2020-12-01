#include "ir/instructions/IRAdd.h"

using namespace hdc;


IRValue *IRAdd::getDestination() {
    return dst;
}

IRValue *IRAdd::getSource1() {
    return src1;
}

IRValue *IRAdd::getSource2() {
    return src2;
}
