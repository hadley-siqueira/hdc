#ifndef HDC_IR_H
#define HDC_IR_H

#include "visitors/ir/IRVisitor.h"

namespace hdc {
    class IR {
        virtual void accept(IRVisitor* visitor)=0;
    };
}

#endif // IR_H
