#include "ast/StructField.h"

using namespace hdc;

StructField::StructField() {
    this->type = NULL;
}

StructField::StructField(Token& name, Type* type) {
    this->token = name;
    this->type = type;
}

StructField::~StructField() {
    if (type != NULL) {
        delete type;
    }
}

void StructField::accept(Visitor* visitor) {
    visitor->visit(this);
}
