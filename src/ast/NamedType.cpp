#include "ast/NamedType.h"

using namespace hdc;

NamedType::NamedType() {
    this->name = nullptr;
}

NamedType::NamedType(IdentifierExpression* name) {
    this->name = name;
}

NamedType::~NamedType() {
    delete name;
}

Type* NamedType::clone() {
    return new NamedType(new IdentifierExpression(this->name));
}

int NamedType::getRank() {
    return 22;
}

void NamedType::accept(Visitor* visitor) {
    visitor->visit(this);
}

IdentifierExpression* NamedType::getName() const {
    return name;
}

void NamedType::setName(IdentifierExpression* value) {
    if (name != nullptr) {
        delete name;
    }

    name = value;
}
