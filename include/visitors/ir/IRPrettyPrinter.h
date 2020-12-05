#ifndef HDC_IR_PRETTYPRINTER_H
#define HDC_IR_PRETTYPRINTER_H

#include <sstream>

#include "visitors/ir/IRVisitor.h"

namespace hdc {
    class IRPrettyPrinter : public IRVisitor {
    public:
        std::string getOutput();

    public:
        void visit(class IRProgram* ir);
        void visit(class IRSourceFile* ir);
        void visit(class IRFunction* ir);

    // instructions
    public:
        void visit(IRLabelDef* ir);

        void visit(IRLoadConstant* ir);

        void visit(IRAdd* ir);

    // values
    public:
        void visit(IRTemporary* ir);
        void visit(IRLabel* ir);
        void visit(IRConstant* ir);

    private:
        std::stringstream output;
    };
}

#endif // IRPRETTYPRINTER_H
