#include <iostream>

#include "ast/types/ArrayType.h"

using namespace hdc;

ArrayType::ArrayType(Type *subtype, Token &token) {
    this->subtype = subtype;
    this->expression = nullptr;
    this->token = token;
    setKind(AST_ARRAY_TYPE);
}

ArrayType::ArrayType(Type *subtype, Expression *expression, Token &token) {
    this->subtype = subtype;
    this->expression = expression;
    this->token = token;
    setKind(AST_ARRAY_TYPE);
}

ArrayType::~ArrayType() {
    delete subtype;
    delete expression;
}

Type* ArrayType::clone() {
    std::cout << __FILE__ << ' ' << __LINE__ << " please implement me\n";
    return new ArrayType(subtype->clone(), expression, token);
}

bool ArrayType::equals(Type *other) {
    if (other->getKind() == AST_ARRAY_TYPE) {
        return true;
    }

    return false;
}

int ArrayType::getRank() {
    return 21;
}

void ArrayType::accept(Visitor *visitor) {
    visitor->visit(this);
}

Type *ArrayType::getSubtype() const {
    return subtype;
}

void ArrayType::setSubtype(Type *value) {
    subtype = value;
}

Expression *ArrayType::getExpression() const {
    return expression;
}

void ArrayType::setExpression(Expression *value) {
    expression = value;
}
