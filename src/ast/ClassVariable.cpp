#include <sstream>

#include "ast/ClassVariable.h"

using namespace hdc;

ClassVariable::ClassVariable() {
    this->type = nullptr;
    setKind(AST_CLASS_VARIABLE);
}

ClassVariable::ClassVariable(Token& token) {
    this->token = token;
    this->type = nullptr;
    setKind(AST_CLASS_VARIABLE);
}

ClassVariable::ClassVariable(Token& token, Type* type) {
    this->token = token;
    this->type = type;
    setKind(AST_CLASS_VARIABLE);
}

std::string ClassVariable::getUniqueCppName() {
    std::stringstream s;

    s << "cv" << localName << '_' << getName();
    return s.str();
}

void ClassVariable::accept(Visitor* visitor) {
    visitor->visit(this);
}
