#ifndef HDC_IRFUNCTION_H
#define HDC_IRFUNCTION_H

#include "IR.h"
#include "ast/Def.h"

namespace hdc {
    class IRFunction : public IR {
    public:
        IRFunction(Def* def);
        ~IRFunction();

    public:
        void add(IR* ir);

    public:
        void accept(IRVisitor* visitor);

    private:
        Def* def;
        std::vector<IR*> body;
    };
}

#endif // IRFUNCTION_H
