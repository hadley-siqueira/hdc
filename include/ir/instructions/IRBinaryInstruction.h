#ifndef HDC_IRBINARYINSTRUCTION_H
#define HDC_IRBINARYINSTRUCTION_H

#include "ir/instructions/IRInstruction.h"
#include "ir/values/IRValue.h"

namespace hdc {
    class IRBinaryInstruction : public IRInstruction {
    public:
        IRValue* getDestination();
        IRValue* getSource1();
        IRValue* getSource2();

    public:
        virtual void accept(IRVisitor* visitor)=0;

    protected:
        IRValue* dst;
        IRValue* src1;
        IRValue* src2;
    };
}

#endif // IRBINARYINSTRUCTION_H
