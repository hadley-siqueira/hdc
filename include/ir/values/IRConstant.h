#ifndef HDC_IR_CONSTANT_H
#define HDC_IR_CONSTANT_H

#include <string>

#include "IRValue.h"

namespace hdc {
    class IRConstant : public IRValue {
    public:
        IRConstant(std::string value);

    public:
        std::string getValue();

    public:
        void accept(IRVisitor *visitor);

    private:
        std::string value;
    };
}

#endif // IRCONSTANT_H
