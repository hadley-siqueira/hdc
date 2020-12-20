#include <sstream>

#include "ast/LocalVariable.h"

using namespace hdc;

LocalVariable::LocalVariable() {
    this->type = nullptr;
    setKind(AST_LOCAL_VARIABLE);
}

LocalVariable::LocalVariable(Token& token) {
    this->token = token;
    this->type = nullptr;
    setKind(AST_LOCAL_VARIABLE);
}

std::string LocalVariable::getUniqueCppName() {
    std::stringstream s;

    s << "lv" << localName << '_' << getName();
    return s.str();
}

void LocalVariable::accept(Visitor* visitor) {
    visitor->visit(this);
}
