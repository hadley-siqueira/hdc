#ifndef HDC_IRLABELDEF_H
#define HDC_IRLABELDEF_H

#include "ir/instructions/IRInstruction.h"
#include "ir/values/IRLabel.h"

namespace hdc {
    class IRLabelDef : public IRInstruction {
    public:
        IRLabelDef(IRLabel* label);
        ~IRLabelDef();

    public:
        void accept(IRVisitor *visitor);

        IRLabel *getLabel();

    private:
        IRLabel* label;
    };
}

#endif // IRLABELDEF_H
