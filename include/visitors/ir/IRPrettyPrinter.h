#ifndef HDC_IR_PRETTYPRINTER_H
#define HDC_IR_PRETTYPRINTER_H

#include <sstream>

#include "visitors/ir/IRVisitor.h"

namespace hdc {
    class IRPrettyPrinter : public IRVisitor {
    public:
        std::string getOutput();

    // instructions
    public:
        void visit(IRAdd* ir);

    // values
    public:
        void visit(IRTemporary* ir);

    private:
        std::stringstream output;
    };
}

#endif // IRPRETTYPRINTER_H
