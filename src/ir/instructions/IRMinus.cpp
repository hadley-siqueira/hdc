#include "ir/instructions/IRMinus.h"

using namespace hdc;

IRMinus::IRMinus(IRValue *dst, IRValue *src1, IRValue *src2) {
    this->dst = dst;
    this->src1 = src1;
    this->src2 = src2;
}

IRMinus::~IRMinus() {
    delete dst;
}

void IRMinus::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
