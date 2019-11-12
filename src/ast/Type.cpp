#include <iostream>

#include "ast/Type.h"

using namespace hdc;

Type::~Type() {
    /* empty */
}

void Type::accept(Visitor* visitor) {
    visitor->visit(this);
}
