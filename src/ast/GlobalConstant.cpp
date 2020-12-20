#include "ast/GlobalConstant.h"

using namespace hdc;

hdc::GlobalConstant::GlobalConstant() {
    this->type = nullptr;
    this->expression = nullptr;
    this->isConstant = false;
    setKind(AST_GLOBAL_CONSTANT);
}

hdc::GlobalConstant::GlobalConstant(hdc::Token& token) {
    this->token = token;
    this->type = nullptr;
    this->expression = nullptr;
    this->isConstant = false;
    setKind(AST_GLOBAL_CONSTANT);
}

hdc::GlobalConstant::GlobalConstant(hdc::Token& token, hdc::Type* type, hdc::Expression* expression) {
    this->token = token;
    this->type = type;
    this->expression = expression;
    this->isConstant = false;
    setKind(AST_GLOBAL_CONSTANT);
}

hdc::GlobalConstant::GlobalConstant(hdc::Token& token, hdc::Expression* expression) {
    this->token = token;
    this->type = nullptr;
    this->expression = expression;
    this->isConstant = false;
    setKind(AST_GLOBAL_CONSTANT);
}

GlobalConstant::~GlobalConstant() {
    delete type;
    delete expression;
}

void GlobalConstant::accept(Visitor* visitor) {
    visitor->visit(this);
}

Expression* GlobalConstant::getExpression() const {
    return expression;
}

void GlobalConstant::setExpression(Expression* value) {
    expression = value;
}

SourceFile* GlobalConstant::getSourceFile() const {
    return sourceFile;
}

void GlobalConstant::setSourceFile(SourceFile* value) {
    sourceFile = value;
}
