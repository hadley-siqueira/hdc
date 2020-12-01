#ifndef HDC_IR_INSTRUCTION_H
#define HDC_IR_INSTRUCTION_H

#include "ir/IR.h"

namespace hdc {
    class IRInstruction : public IR {
    public:
        virtual void accept(IRVisitor* visitor)=0;

    };
}

#endif // IRINSTRUCTION_H
