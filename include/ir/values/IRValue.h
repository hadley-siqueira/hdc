#ifndef HDC_IR_VALUE_H
#define HDC_IR_VALUE_H

#include "ir/IR.h"

namespace hdc {
    class IRValue : public IR {
    public:
        virtual void accept(IRVisitor* visitor)=0;
    };
}

#endif // IRVALUE_H
