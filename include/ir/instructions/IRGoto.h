#ifndef HDC_IRGOTO_H
#define HDC_IRGOTO_H

#include "ir/instructions/IRInstruction.h"
#include "ir/values/IRLabel.h"

namespace hdc {
    class IRGoto : public IRInstruction {
    public:
        IRGoto(IRLabel* label);

    public:
        IRLabel* getLabel();

    public:
        void accept(IRVisitor *visitor);

    private:
        IRLabel* label;
    };
}

#endif
