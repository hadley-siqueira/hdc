#include "visitors/TACPrettyPrinter.h"

#include "tac/TACAdd.h"

using namespace hdc;

void TACPrettyPrinter::visit(TACAdd* tac) {
    output << "add %" << tac->getDestination();
    output << ", %" << tac->getSource1();
    output << ", %" << tac->getSource2();
}
