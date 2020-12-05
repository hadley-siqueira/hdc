#ifndef HDC_IRCONSTANT_H
#define HDC_IRCONSTANT_H

#include "ir/instructions/IRUnaryInstruction.h"

namespace hdc {
    class IRLoadConstant : public IRUnaryInstruction {
    public:
        IRLoadConstant(IRValue* dst, IRValue* src);

    public:
        void accept(IRVisitor *visitor);
    };
}

#endif // IRCONSTANT_H
