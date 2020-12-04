#include "ir/IRProgram.h"

using namespace hdc;

IRProgram::~IRProgram() {
    for (int i = 0; i < sfiles.size(); ++i) {
        delete sfiles[i];
    }
}

void IRProgram::addIRSourceFile(IRSourceFile *file) {
    sfiles.push_back(file);
}

int IRProgram::n_sourceFiles() {
    return sfiles.size();
}

IRSourceFile *IRProgram::getIRSourceFile(int i) {
    return sfiles[i];
}

void IRProgram::accept(IRVisitor *visitor) {
    visitor->visit(this);
}
