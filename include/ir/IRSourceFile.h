#ifndef HDC_IRSOURCEFILE_H
#define HDC_IRSOURCEFILE_H

#include "IR.h"
#include "ast/SourceFile.h"

namespace hdc {
    class IRSourceFile : public IR {
    public:
        IRSourceFile(SourceFile* file);

    public:
        void accept(IRVisitor* visitor);

    private:
        SourceFile* sfile;
    };
}

#endif // IRSOURCEFILE_H
