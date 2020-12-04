#ifndef HDC_IRFUNCTION_H
#define HDC_IRFUNCTION_H

#include "IR.h"
#include "ast/Def.h"
#include "ir/instructions/IRLabelDef.h"

namespace hdc {
    class IRFunction : public IR {
    public:
        IRFunction(Def* def);
        ~IRFunction();

    public:
        void add(IR* ir);
        int n_instructions();
        IR* getInstruction(int i);

    public:
        void accept(IRVisitor* visitor);

        IRLabelDef *getLabelName() const;

    private:
        Def* def;
        std::vector<IR*> instructions;
        IRLabelDef* labelName;
    };
}

#endif // IRFUNCTION_H
