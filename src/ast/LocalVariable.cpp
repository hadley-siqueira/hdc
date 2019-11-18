#include "ast/LocalVariable.h"

using namespace hdc;

LocalVariable::LocalVariable() {
    this->type = nullptr;
}

LocalVariable::LocalVariable(Token& token) {
    this->token = token;
    this->type = nullptr;
}

void LocalVariable::accept(Visitor* visitor) {
    visitor->visit(this);
}
