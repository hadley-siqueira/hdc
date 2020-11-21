#ifndef HDC_TAC_H
#define HDC_TAC_H

namespace hdc {
    enum TACKind {
        TAC_LABEL,

        /* binary */
        TAC_ADD,

        /* conditional jumps */
        TAC_IFZ,
        TAC_GOTO,

        /* literals */
        TAC_CONST_I32
    };

    class TAC {
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
