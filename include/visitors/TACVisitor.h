#ifndef HDC_TACVISITOR_H
#define HDC_TACVISITOR_H

namespace hdc {
    class TACVisitor {
    public:
        virtual void visit(class TACAdd* tac)=0;
    };
}

#endif // TACVISITOR_H
