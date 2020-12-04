#include "ir/IRFunction.h"

using namespace hdc;

IRFunction::IRFunction(Def *def) {
    this->def = def;
    labelName = new IRLabelDef(new IRLabel(def->getName()));
}

IRFunction::~IRFunction() {
    for (int i = 0; i < instructions.size(); ++i) {
        delete instructions[i];
    }
}

void IRFunction::add(IR *ir) {
    instructions.push_back(ir);
}

int IRFunction::n_instructions() {
    return instructions.size();
}

IR *IRFunction::getInstruction(int i) {
    return instructions[i];
}

void IRFunction::accept(IRVisitor *visitor) {
    visitor->visit(this);
}

IRLabelDef *IRFunction::getLabelName() const {
    return labelName;
}
