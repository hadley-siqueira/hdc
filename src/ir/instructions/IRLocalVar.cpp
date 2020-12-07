#include "ir/instructions/IRLocalVar.h"

using namespace hdc;

IRLocalVar::IRLocalVar(IRValue* dst, int offset) {
    this->offset = offset;
    this->dst = dst;
    dst->setCreatedBy(this);
}

IRLocalVar::~IRLocalVar() {
    delete dst;
}

IRValue *IRLocalVar::getDestination() {
    return dst;
}

int IRLocalVar::getOffset() {
    return offset;
}

void IRLocalVar::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
