#ifndef HDC_IRSTORE_H
#define HDC_IRSTORE_H

#include "ir/instructions/IRInstruction.h"
#include "ir/values/IRValue.h"

namespace hdc {
    class IRStore : public IRInstruction {
    public:
        IRStore(IRValue* dst, IRValue* src);
        IRStore(IRValue *dst, IRValue *src, IRValue* offset);
        ~IRStore();

        IRValue* getDestination();
        IRValue* getSource();
        IRValue* getOffset();

    public:
        void accept(IRVisitor *visitor);

    private:
        IRValue* dst;
        IRValue* src;
        IRValue* offset;

    };
}

#endif // IRSTORE_H
