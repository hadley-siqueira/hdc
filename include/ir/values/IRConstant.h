#ifndef HDC_IR_CONSTANT_H
#define HDC_IR_CONSTANT_H

#include <string>

#include "IRValue.h"
#include "token/Token.h"

namespace hdc {
    class IRConstant : public IRValue {
    public:
        IRConstant(Token token);

    public:
        std::string getValue();

    public:
        void accept(IRVisitor *visitor);

    private:
        Token token;
    };
}

#endif // IRCONSTANT_H
