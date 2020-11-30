#include <sstream>
#include <iostream>
#include "tac/TAC.h"
#include "gen/x86_64/gen_x86_64.h"

using namespace hdc;

Generator_x86_64::Generator_x86_64() {
    regCounter = -1;

    regs_s.push_back("%esi");
    regs_s.push_back("%edi");
    regs_s.push_back("%r8d");
    regs_s.push_back("%r9d");
    regs_s.push_back("%r10d");
    regs_s.push_back("%r11d");
    regs_s.push_back("%r12d");
    regs_s.push_back("%r13d");
    regs_s.push_back("%r14d");
    regs_s.push_back("%r15d");

    //regs_s.push_back("%ecx");
    //regs_s.push_back("%edx"); // ecx eax edx
}

void hdc::Generator_x86_64::generate(std::vector<TAC> &tacs) {
    for (int i = 0; i < tacs.size(); ++i) {
        emit(tacs[i]);
    }

    std::cout << output.str();
}

void Generator_x86_64::emitInstruction(std::string s) {
    //output << "    " << s << " %r" << (regCounter) << "d, %r" << (regCounter - 1) << "d";
    output << "    " << s << " " << regs_s[regCounter] << ", " << regs_s[regCounter - 1];
}

void hdc::Generator_x86_64::emit(TAC& tac) {
    switch (tac.kind) {
    case TAC_LABEL:
        output << "." << tac.label << ":";
        break;

    case TAC_END_EXPR:
        regCounter = -1;
        break;

    case TAC_SLL:
        output << "    movl " << regs_s[regCounter] <<", %ecx\n";
        output << "    sall %cl, " << regs_s[regCounter - 1];
        --regCounter;
        break;

    case TAC_BITWISE_AND:
        emitInstruction("andl");
        --regCounter;
        break;

    case TAC_BITWISE_XOR:
        emitInstruction("xorl");
        --regCounter;
        break;

    case TAC_BITWISE_OR:
        emitInstruction("orl");
        --regCounter;
        break;

    case TAC_ADD:
        emitInstruction("addl");
        --regCounter;
        break;

    case TAC_SUB:
        emitInstruction("subl");
        --regCounter;
        break;

    case TAC_IFZ:
        output << "    cmpl $0, " << regs_s[regCounter];
        output << "\n    je ." << tac.label;
        break;

    case TAC_GOTO:
        output << "    jmp ." << tac.label;
        break;

    case TAC_CONST_I32:
        ++regCounter;
        output << "    mov $" << tac.label << ", " << regs_s[regCounter];
        break;

    default:
        output << "x86_64 gen ERROR: undefined tac";
        break;
    }

    output << '\n';
}
