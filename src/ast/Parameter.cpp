#include "ast/Parameter.h"

using namespace hdc;

Parameter::Parameter() {
    this->type = NULL;
}

Parameter::Parameter(Token& name, Type* type) {
    this->token = name;
    this->type = type;
}

Parameter::~Parameter() {
    if (type != NULL) {
        delete type;
    }
}

void Parameter::accept(Visitor* visitor) {
    visitor->visit(this);
}
