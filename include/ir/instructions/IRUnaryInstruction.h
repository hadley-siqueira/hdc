#ifndef HDC_IRUNARYINSTRUCTION_H
#define HDC_IRUNARYINSTRUCTION_H

#include "ir/instructions/IRInstruction.h"
#include "ir/values/IRValue.h"

namespace hdc {
    class IRUnaryInstruction : public IRInstruction {
    public:
        IRValue* getDestination();
        IRValue* getSource();

    public:
        virtual void accept(IRVisitor* visitor)=0;

    protected:
        IRValue* dst;
        IRValue* src;
    };
}

#endif // IRUnaryINSTRUCTION_H
