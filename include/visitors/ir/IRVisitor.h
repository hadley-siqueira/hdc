#ifndef HDC_IR_VISITOR_H
#define HDC_IR_VISITOR_H

namespace hdc {
    class IRVisitor {
    public:
        virtual void visit(class IRAdd* ir)=0;
    };
}

#endif // IRVISITOR_H
