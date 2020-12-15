#include <sstream>

#include "ast/Parameter.h"

using namespace hdc;

Parameter::Parameter() {
    this->type = nullptr;
}

Parameter::Parameter(Token& name, Type* type) {
    this->token = name;
    this->type = type;
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
