#ifndef HDC_IRSOURCEFILE_H
#define HDC_IRSOURCEFILE_H

#include "IR.h"
#include "ast/SourceFile.h"
#include "ir/IRFunction.h"

namespace hdc {
    class IRSourceFile : public IR {
    public:
        IRSourceFile(SourceFile* file);

    public:
        int n_functions();
        IRFunction* getFunction(int i);
        void addFunction(IRFunction* f);

    public:
        void accept(IRVisitor* visitor);

    private:
        SourceFile* sfile;
        std::vector<IRFunction*> functions;
    };
}

#endif // IRSOURCEFILE_H
