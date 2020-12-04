#include "ir/IRSourceFile.h"

using namespace hdc;

IRSourceFile::IRSourceFile(SourceFile *file) {
    sfile = file;
}

void IRSourceFile::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
