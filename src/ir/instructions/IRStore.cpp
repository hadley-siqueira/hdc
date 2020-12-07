#include "ir/instructions/IRStore.h"

using namespace hdc;

IRStore::IRStore(IRValue *dst, IRValue *src) {
    this->dst = dst;
    this->src = src;
    this->offset = nullptr;

    dst->makeUsedBy(this);
    src->makeUsedBy(this);
}

IRStore::IRStore(IRValue *dst, IRValue *src, IRValue* offset) {
    this->dst = dst;
    this->src = src;
    this->offset = offset;

    dst->makeUsedBy(this);
    src->makeUsedBy(this);
    offset->setCreatedBy(this);
}

IRStore::~IRStore() {
    delete offset;
}

IRValue *IRStore::getDestination() {
    return dst;
}

IRValue *IRStore::getSource() {
    return src;
}

IRValue *IRStore::getOffset() {
    return offset;
}

void IRStore::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
