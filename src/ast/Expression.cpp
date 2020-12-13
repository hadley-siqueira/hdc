#include "ast/Expression.h"

using namespace hdc;

Expression::Expression() {
    type = nullptr;
}

Expression::~Expression() {
    delete type;
}

/* Visitors */
void Expression::accept(Visitor* visitor) {
    visitor->visit(this);
}

Type* Expression::getType() const {
    return type;
}

void Expression::setType(Type* value) {
    if (type != nullptr) {
        delete type;
    }

    type = value;
}
