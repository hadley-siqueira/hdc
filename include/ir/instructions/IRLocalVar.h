#ifndef IRLOCALVAR_H
#define IRLOCALVAR_H

#include "ir/instructions/IRInstruction.h"
#include "ir/values/IRValue.h"

namespace hdc {
    class IRLocalVar : public IRInstruction {
    public:
        IRLocalVar(IRValue* dst, int offset);
        ~IRLocalVar();

    public:
        IRValue* getDestination();
        int getOffset();

    public:
        void accept(IRVisitor *visitor);

    private:
        int offset;
        IRValue* dst;
    };
}

#endif // IRLOCALVAR_H
