#ifndef HDC_IR_TEMPORARY_H
#define HDC_IR_TEMPORARY_H

#include "IRValue.h"

namespace hdc {
    class IRTemporary : public IRValue {
    public:
        unsigned int getTemporaryValue();

    private:
        unsigned int tmp;
    };
}

#endif // IRTEMPORARY_H
