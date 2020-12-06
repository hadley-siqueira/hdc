#include "ir/instructions/IRLabelDef.h"

using namespace hdc;


IRLabelDef::IRLabelDef(IRLabel *label) {
    this->label = label;
    label->setCreatedBy(this);
}

IRLabelDef::~IRLabelDef() {
    delete label;
}

void IRLabelDef::accept(IRVisitor *visitor) {
    visitor->visit(this);
}

IRLabel *IRLabelDef::getLabel() {
    return label;
}
