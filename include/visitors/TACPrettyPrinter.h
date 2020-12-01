#ifndef HDC_TACPRETTYPRINTER_H
#define HDC_TACPRETTYPRINTER_H

#include <sstream>

#include "visitors/TACVisitor.h"

namespace hdc {
    class TACPrettyPrinter : public TACVisitor {
    public:
        void visit(TACAdd* tac);

    private:
        std::stringstream output;
    };
}

#endif // TACPRETTYPRINTER_H
