#include "ir/instructions/IRAdd.h"

using namespace hdc;

IRAdd::IRAdd(IRValue *dst, IRValue *src1, IRValue *src2) {
    setDestination(dst);
    setSource1(src1);
    setSource2(src2);
}

IRAdd::~IRAdd() {
    delete dst;
}

void IRAdd::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
