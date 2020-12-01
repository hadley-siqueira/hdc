#ifndef HDC_IR_H
#define HDC_IR_H

#include "visitors/ir/IRVisitor.h"

namespace hdc {
    enum IRKind {
        IR_ADD,
        IR_TEMPORARY
    };

    class IR {
    public:
        virtual void accept(IRVisitor* visitor)=0;

    private:
        IRKind kind;
    };
}

#endif // IR_H
