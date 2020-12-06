#include "ir/values/IRValue.h"

using namespace hdc;

void IRValue::setCreatedBy(IR *ir) {
    createdBy = ir;
}

void IRValue::makeUsedBy(IR *ir) {
    usedBy.insert(ir);
}
