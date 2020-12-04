#include "ir/IRFunction.h"

using namespace hdc;

IRFunction::IRFunction(Def *def) {
    this->def = def;
}

IRFunction::~IRFunction() {
    for (int i = 0; i < body.size(); ++i) {
        delete body[i];
    }
}

void IRFunction::add(IR *ir) {
    body.push_back(ir);
}

void IRFunction::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
