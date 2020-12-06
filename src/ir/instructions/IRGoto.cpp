#include "ir/instructions/IRGoto.h"

using namespace hdc;

IRGoto::IRGoto(IRLabel *label) {
    this->label = label;
    label->makeUsedBy(this);
}

IRLabel *IRGoto::getLabel() {
    return label;
}

void IRGoto::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
