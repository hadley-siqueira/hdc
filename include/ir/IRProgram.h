#ifndef HDC_IRPROGRAM_H
#define HDC_IRPROGRAM_H

#include <vector>

#include "ir/IR.h"
#include "ir/IRSourceFile.h"

namespace hdc {
    class IRProgram : public IR {
    public:
        ~IRProgram();

    public:
        void addIRSourceFile(IRSourceFile* file);

        int n_sourceFiles();
        IRSourceFile* getIRSourceFile(int i);

    public:
        void accept(IRVisitor *visitor);

    private:
        std::vector<IRSourceFile*> sfiles;
    };
}

#endif // IRPROGRAM_H
