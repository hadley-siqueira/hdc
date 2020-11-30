#ifndef HDC_TAC_H
#define HDC_TAC_H

#include <set>

namespace hdc {
    enum TACKind {
        TAC_LABEL,

        TAC_RETURN,
        TAC_RETURN_VALUE,

        TAC_END_EXPR, // this TAC is used to stack code generation. It resets the stack expression eval when the expr ends

        TAC_LCALL,
        TAC_PUSH_PARAM,
        TAC_GET_VAR,

        // memory
        TAC_SW,
        TAC_LW,

        /* binary */
        TAC_SLL,

        TAC_BITWISE_AND,
        TAC_BITWISE_XOR,
        TAC_BITWISE_OR,

        TAC_ADD,
        TAC_SUB,

        /* conditional jumps */
        TAC_IFZ,
        TAC_GOTO,

        /* literals */
        TAC_CONST_I32
    };

    class TAC {
    public:
        TAC();

    public:
        std::string to_str(bool printSets=false);
        bool usesTemporary(int t);
        bool generateTemporary(int t);

    public:
        int kind;
        int opcode;
        int src1;
        int src2;
        int dst;
        std::string label;
        std::set<int> before;
        std::set<int> after;
    };
}

#endif // HDC_TAC_H
