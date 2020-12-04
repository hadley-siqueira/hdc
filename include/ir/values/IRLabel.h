#ifndef HDC_IRLABEL_H
#define HDC_IRLABEL_H

#include <string>

#include "IRValue.h"

namespace hdc {
    class IRLabel : public IRValue {
    public:
        IRLabel(std::string value);

    public:
        std::string getValue();

    public:
        void accept(IRVisitor *visitor);

    private:
        std::string value;
    };
}

#endif // IRLABEL_H
