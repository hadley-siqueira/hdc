#ifndef HDC_IR_TEMPORARY_H
#define HDC_IR_TEMPORARY_H

#include "IRValue.h"

namespace hdc {
    class IRTemporary : public IRValue {
    public:
        IRTemporary(unsigned int value);

    public:
        unsigned int getValue();

    public:
        void accept(IRVisitor *visitor);

    private:
        unsigned int value;
    };
}

#endif // IRTEMPORARY_H
