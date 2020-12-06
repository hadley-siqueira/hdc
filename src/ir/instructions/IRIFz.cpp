#include "ir/instructions/IRIFz.h"

using namespace hdc;
IRIFz::IRIFz(IRValue *value, IRLabel *label) {
    this->value = value;
    this->label = label;

    value->makeUsedBy(this);
    label->makeUsedBy(this);
}

IRValue *IRIFz::getSource() {
    return value;
}

IRLabel *IRIFz::getLabel() {
    return label;
}

void IRIFz::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
