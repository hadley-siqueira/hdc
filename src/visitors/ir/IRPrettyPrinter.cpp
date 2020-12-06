#include <iostream>

#include "ir/ir.h"
#include "visitors/ir/IRPrettyPrinter.h"

using namespace hdc;

std::string IRPrettyPrinter::getOutput() {
    return output.str();
}

void IRPrettyPrinter::visit(IRProgram *ir) {
    for (int i = 0; i < ir->n_sourceFiles(); ++i) {
        ir->getIRSourceFile(i)->accept(this);
    }
}

void IRPrettyPrinter::visit(IRSourceFile *ir) {
    for (int i = 0; i < ir->n_functions(); ++i) {
        ir->getFunction(i)->accept(this);
        output << "\n\n";
    }
}

void IRPrettyPrinter::visit(IRFunction *ir) {
    ir->getLabelName()->accept(this);

    for (int i = 0; i < ir->n_instructions(); ++i) {
        ir->getInstruction(i)->accept(this);
    }
}

void IRPrettyPrinter::visit(IRLabelDef *ir) {
    output << ir->getLabel()->getValue() << ":\n";
}

void IRPrettyPrinter::visit(IRGoto *ir) {
    output << "    goto ";
    ir->getLabel()->accept(this);
    output << '\n';
}

void IRPrettyPrinter::visit(IRIFz *ir) {
    output << "    if !%";
    ir->getSource()->accept(this);

    output << " goto ";
    ir->getLabel()->accept(this);
    output << '\n';
}

void IRPrettyPrinter::visit(IRLoadConstant *ir) {
    output << "    li %";
    ir->getDestination()->accept(this);
    output << ", ";
    ir->getSource()->accept(this);
    output << '\n';
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

void IRPrettyPrinter::visit(IRMinus *ir) {
    output << "    sub %";
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

void IRPrettyPrinter::visit(IRLabel *ir) {
    output << ir->getValue();
}

void IRPrettyPrinter::visit(IRConstant *ir) {
    output << ir->getValue();
}
