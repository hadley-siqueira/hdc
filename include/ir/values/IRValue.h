#ifndef HDC_IR_VALUE_H
#define HDC_IR_VALUE_H

#include <set>

#include "ir/IR.h"

namespace hdc {
    class IRValue : public IR {
    public:
        void setCreatedBy(IR* ir);
        void makeUsedBy(IR* ir);

    public:
        virtual void accept(IRVisitor* visitor)=0;

    protected:
        std::set<IR*> usedBy;
        IR* createdBy;
    };
}

#endif // IRVALUE_H
