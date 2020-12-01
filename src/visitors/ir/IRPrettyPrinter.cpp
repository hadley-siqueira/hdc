#include "ir/ir.h"
#include "visitors/ir/IRPrettyPrinter.h"

using namespace hdc;

std::string IRPrettyPrinter::getOutput() {
    return output.str();
}

void IRPrettyPrinter::visit(IRAdd *ir) {
    output << "    add %";
    ir->getDestination()->accept(this);

    output << ", %";
    ir->getSource1()->accept(this);

    output << ", %";
    ir->getSource2()->accept(this);
    output << "\n";
}

void IRPrettyPrinter::visit(IRTemporary *ir) {
    output << ir->getValue();
}
