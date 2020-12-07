#ifndef HDC_IR_VISITOR_H
#define HDC_IR_VISITOR_H

namespace hdc {
    class IRVisitor {
    public:
        virtual void visit(class IRProgram* ir)=0;
        virtual void visit(class IRSourceFile* ir)=0;
        virtual void visit(class IRFunction* ir)=0;

    // instructions
    public:
        virtual void visit(class IRLabelDef* ir)=0;
        virtual void visit(class IRGoto* ir)=0;
        virtual void visit(class IRIFz* ir)=0;
        virtual void visit(class IRLocalVar* ir)=0;

        virtual void visit(class IRLoadConstant* ir)=0;
        virtual void visit(class IRStore* ir)=0;

        virtual void visit(class IRAdd* ir)=0;
        virtual void visit(class IRMinus* ir)=0;

    // values
    public:
        virtual void visit(class IRTemporary* ir)=0;
        virtual void visit(class IRLabel* ir)=0;
        virtual void visit(class IRConstant* ir)=0;

    };
}

#endif // IRVISITOR_H
