#include <sstream>

#include "ast/Parameter.h"

using namespace hdc;

Parameter::Parameter() {
    this->type = nullptr;
    setKind(AST_PARAMETER);
}

Parameter::Parameter(Token& name, Type* type) {
    this->token = name;
    this->type = type;
    setKind(AST_PARAMETER);
}

Parameter::~Parameter() {

}

std::string Parameter::getUniqueCppName() {
    std::stringstream s;

    s << 'p' << localName << '_' << getName();
    return s.str();
}

void Parameter::accept(Visitor* visitor) {
    visitor->visit(this);
}
