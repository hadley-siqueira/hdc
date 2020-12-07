#include "ir/instructions/IRLoadConstant.h"

using namespace hdc;

IRLoadConstant::IRLoadConstant(IRValue *dst, IRValue *src) {
    setDestination(dst);
    setSource(src);
}

void IRLoadConstant::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
