#include "symtab/Symbol.h"
#include "ast/AST.h"

using namespace hdc;

Symbol::Symbol(Class* klass) {
    kind = SYMBOL_CLASS;
    descriptor = klass;
}

hdc::Symbol::Symbol(hdc::Def* def) {
    kind = SYMBOL_DEF;
    descriptor = def;
}

hdc::Symbol::Symbol(hdc::LocalVariable* var) {
    kind = SYMBOL_LOCAL_VARIABLE;
    descriptor = var;
}

Symbol::Symbol(Parameter* parameter) {
    kind = SYMBOL_PARAMETER;
    descriptor = parameter;
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
