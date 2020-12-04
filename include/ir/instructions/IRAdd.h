#ifndef HDC_IR_ADD_H
#define HDC_IR_ADD_H

#include "ir/instructions/IRBinaryInstruction.h"

namespace hdc {
    class IRAdd : public IRBinaryInstruction {
    public:
        IRAdd(IRValue* dst, IRValue* src1, IRValue* src2);

    public:
        void accept(IRVisitor* visitor);

    };
}

#endif // HDC_IR_ADD_H
