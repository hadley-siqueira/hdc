#include "ast/GlobalVariable.h"

using namespace hdc;

hdc::GlobalVariable::GlobalVariable() {
    this->type = nullptr;
    this->expression = nullptr;
}

hdc::GlobalVariable::GlobalVariable(hdc::Token& token) {
    this->token = token;
    this->type = nullptr;
    this->expression = nullptr;
}

hdc::GlobalVariable::GlobalVariable(hdc::Token& token, hdc::Type* type) {
    this->token = token;
    this->type = type;
    this->expression = nullptr;
}

hdc::GlobalVariable::GlobalVariable(hdc::Token& token, hdc::Type* type, hdc::Expression* expression) {
    this->token = token;
    this->type = type;
    this->expression = expression;
}

hdc::GlobalVariable::GlobalVariable(hdc::Token& token, hdc::Expression* expression) {
    this->token = token;
    this->type = nullptr;
    this->expression = expression;
}

GlobalVariable::~GlobalVariable() {
    delete type;
    delete expression;
}

void GlobalVariable::accept(Visitor* visitor) {
    visitor->visit(this);
}

Expression* GlobalVariable::getExpression() const {
    return expression;
}

void GlobalVariable::setExpression(Expression* value) {
    expression = value;
}

SourceFile* GlobalVariable::getSourceFile() const {
    return sourceFile;
}

void GlobalVariable::setSourceFile(SourceFile* value) {
    sourceFile = value;
}
