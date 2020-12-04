#include "ir/values/IRLabel.h"

using namespace hdc;

IRLabel::IRLabel(std::string value) {
    this->value = value;
}

std::string IRLabel::getValue() {
    return value;
}

void IRLabel::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
