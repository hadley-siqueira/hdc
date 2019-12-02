#include "symtab/Symbol.h"
#include "ast/AST.h"

using namespace hdc;

Symbol::Symbol(Class* klass) {
    kind = SYMBOL_CLASS;
    descriptor = klass;
    line = klass->getLine();
    column = klass->getColumn();
}

hdc::Symbol::Symbol(hdc::Def* def) {
    kind = SYMBOL_DEF;
    descriptor = def;
    line = def->getLine();
    column = def->getColumn();
}

hdc::Symbol::Symbol(hdc::LocalVariable* var) {
    kind = SYMBOL_LOCAL_VARIABLE;
    descriptor = var;
    line = var->getLine();
    column = var->getColumn();
}

Symbol::Symbol(Parameter* parameter) {
    kind = SYMBOL_PARAMETER;
    descriptor = parameter;
    line = parameter->getLine();
    column = parameter->getColumn();
}

Symbol::Symbol(ClassVariable* var) {
    kind = SYMBOL_CLASS_VARIABLE;
    descriptor = var;
    line = var->getLine();
    column = var->getColumn();
}

Symbol::Symbol(GlobalVariable* var) {
    if (var->getIsConstant()) {
        kind = SYMBOL_GLOBAL_CONSTANT;
    } else {
        kind = SYMBOL_GLOBAL_VARIABLE;
    }

    descriptor = var;
    line = var->getLine();
    column = var->getColumn();
}

void* Symbol::getDescriptor() const {
    return descriptor;
}

void Symbol::setDescriptor(void* value) {
    descriptor = value;
}

int Symbol::getLine() const
{
    return line;
}

void Symbol::setLine(int value)
{
    line = value;
}

int Symbol::getColumn() const
{
    return column;
}

void Symbol::setColumn(int value)
{
    column = value;
}

SymbolKind Symbol::getKind() const {
    return kind;
}

void Symbol::setKind(const SymbolKind& value) {
    kind = value;
}
