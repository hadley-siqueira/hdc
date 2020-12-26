#include "ast/Expression.h"

using namespace hdc;

Expression::Expression() {
    type = nullptr;
    cppTemp = -1;
}

Expression::~Expression() {
    delete type;
}

/* Visitors */
void Expression::accept(Visitor* visitor) {
    visitor->visit(this);
}

int Expression::getCppTemp() const {
    return cppTemp;
}

void Expression::setCppTemp(int value) {
    cppTemp = value;
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
