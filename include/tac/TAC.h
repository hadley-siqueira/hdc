#ifndef HDC_TAC_H
#define HDC_TAC_H

namespace hdc {
    enum TACKind {
        TAC_LABEL,

        TAC_END_EXPR, // this TAC is used to stack code generation. It resets the stack expression eval when the expr ends

        /* binary */
        TAC_SLL,

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
        std::string to_str();

    public:
        int kind;
        int opcode;
        int src1;
        int src2;
        int dst;
        std::string label;
    };
}

#endif // HDC_TAC_H
