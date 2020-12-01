#include <sstream>

#include "tac/TACAdd.h"

using namespace hdc;

TACAdd::TACAdd(int dst, int src1, int src2) {
    this->kind = TAC_ADD;
    this->dst = dst;
    this->src1 = src1;
    this->src2 = src2;
}

int TACAdd::getDestination() {
    return dst;
}

int TACAdd::getSource1() {
    return src1;
}

int TACAdd::getSource2() {
    return src2;
}
