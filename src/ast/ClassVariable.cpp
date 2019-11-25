#include "ast/ClassVariable.h"

using namespace hdc;

ClassVariable::ClassVariable() {
    this->type = nullptr;
}

ClassVariable::ClassVariable(Token& token) {
    this->token = token;
    this->type = nullptr;
}

ClassVariable::ClassVariable(Token& token, Type* type) {
    this->token = token;
    this->type = type;
}

void ClassVariable::accept(Visitor* visitor) {
    visitor->visit(this);
}
