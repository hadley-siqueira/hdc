#ifndef HDC_IRIFZ_H
#define HDC_IRIFZ_H

#include "ir/instructions/IRInstruction.h"
#include "ir/values/IRValue.h"
#include "ir/values/IRLabel.h"

namespace hdc {
    class IRIFz : public IRInstruction {
    public:
        IRIFz(IRValue* value, IRLabel* label);

    public:
        IRValue* getSource();
        IRLabel* getLabel();

    public:
        void accept(IRVisitor *visitor);

    private:
        IRValue* value;
        IRLabel* label;
    };
}

#endif
