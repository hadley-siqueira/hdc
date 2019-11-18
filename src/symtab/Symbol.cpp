#include "symtab/Symbol.h"
#include "ast/AST.h"

using namespace hdc;

hdc::Symbol::Symbol(hdc::Def* def) {
    this->kind = SYMBOL_DEF;
    this->descriptor = def;
}

hdc::Symbol::Symbol(hdc::LocalVariable* var) {
    this->kind = SYMBOL_LOCAL_VARIABLE;
    this->descriptor = var;
}

Symbol::Symbol(Parameter* parameter) {
    this->kind = SYMBOL_PARAMETER;
    this->descriptor = parameter;
}

void* Symbol::getDescriptor() const {
    return descriptor;
}

void Symbol::setDescriptor(void* value) {
    descriptor = value;
}

SymbolKind Symbol::getKind() const {
    return kind;
}

void Symbol::setKind(const SymbolKind& value) {
    kind = value;
}
