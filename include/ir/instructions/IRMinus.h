#ifndef HDC_IR_MINUS_H
#define HDC_IR_MINUS_H

#include "ir/instructions/IRBinaryInstruction.h"

namespace hdc {
    class IRMinus : public IRBinaryInstruction {
    public:
        IRMinus(IRValue* dst, IRValue* src1, IRValue* src2);
        ~IRMinus();

    public:
        void accept(IRVisitor* visitor);

    };
}

#endif // HDC_IR_MINUS_H
