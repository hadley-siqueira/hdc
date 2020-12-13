#include "ast/VoidType.h"

using namespace hdc;

VoidType::VoidType() {
    this->kind = AST_VOID_TYPE;
}

VoidType::VoidType(Token& token) {
    this->token = token;
    this->kind = AST_VOID_TYPE;
}

Type* VoidType::clone() {
    return new VoidType(token);
}

int VoidType::getRank() {
    return 0;
}


void VoidType::accept(Visitor* visitor) {
    visitor->visit(this);
}
