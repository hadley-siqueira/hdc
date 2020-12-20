#include "ast/StructField.h"

using namespace hdc;

StructField::StructField() {
    this->type = nullptr;
    setKind(AST_STRUCT_FIELD);
}

StructField::StructField(Token& name, Type* type) {
    this->token = name;
    this->type = type;
    setKind(AST_STRUCT_FIELD);
}

StructField::~StructField() {
    if (type != nullptr) {
        delete type;
    }
}

void StructField::accept(Visitor* visitor) {
    visitor->visit(this);
}
