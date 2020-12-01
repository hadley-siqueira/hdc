#ifndef HDC_IR_ADD_H
#define HDC_IR_ADD_H

#include "ir/instructions/IRInstruction.h"
#include "ir/values/IRValue.h"

namespace hdc {
    class IRAdd : public IRInstruction {
    public:
        IRAdd(IRValue* dst, IRValue* src1, IRValue* src2);

    public:
        IRValue* getDestination();
        IRValue* getSource1();
        IRValue* getSource2();

    private:
        IRValue* dst;
        IRValue* src1;
        IRValue* src2;
    };
}

#endif // HDC_IR_ADD_H
