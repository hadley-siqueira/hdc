#include <iostream>

#include "ast/types/Type.h"

using namespace hdc;

Type::~Type() {
    /* empty */
}

bool Type::equals(Type* other) {
    return other->getKind() == this->kind;
}

void Type::accept(Visitor* visitor) {
    visitor->visit(this);
}
