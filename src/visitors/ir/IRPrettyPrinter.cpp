#include "ir/ir.h"
#include "visitors/ir/IRPrettyPrinter.h"

using namespace hdc;


void IRPrettyPrinter::visit(IRAdd *ir) {
    output << "    add %";
    output << ir->getDestination();
}

void IRPrettyPrinter::visit(IRTemporary *ir) {
    output << ir->getTemporaryValue();
}
