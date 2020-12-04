#include "ir/IRSourceFile.h"

using namespace hdc;

IRSourceFile::IRSourceFile(SourceFile *file) {
    sfile = file;
}

int IRSourceFile::n_functions() {
    return functions.size();
}

IRFunction *IRSourceFile::getFunction(int i) {
    return functions[i];
}

void IRSourceFile::addFunction(IRFunction *f) {
    functions.push_back(f);
}

void IRSourceFile::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
