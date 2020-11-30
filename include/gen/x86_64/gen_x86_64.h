#ifndef HDC_GEN_X86_64_H
#define HDC_GEN_X86_64_H

#include <sstream>
#include <vector>

#include "tac/TAC.h"

namespace hdc {
    // this class generates x86-64 code as a stack machine
    class Generator_x86_64 {
    public:
        Generator_x86_64();

    public:
        void generate(std::vector<TAC>& tacs);

    private:
        void emit(TAC& tac);
        void emitInstruction(std::string s);

    private:
        std::stringstream output;
        int regCounter;
        std::vector<std::string> regs_s;
    };
}

#endif // GEN_X86_64_H
