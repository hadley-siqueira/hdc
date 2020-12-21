#include "ast/BinaryOperator.h"

using namespace hdc;

/* Constructors */
BinaryOperator::BinaryOperator() {
    left = nullptr;
    right = nullptr;
}

BinaryOperator::BinaryOperator(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
    left->setParentNode(this);
    right->setParentNode(this);
}

BinaryOperator::BinaryOperator(Token& oper, Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
    this->oper = oper;
    left->setParentNode(this);
    right->setParentNode(this);
}

/* Destructors */
BinaryOperator::~BinaryOperator() {
    delete left;
    delete right;
}

/* Setters */
void BinaryOperator::setLeft(Expression* left) {
    if (this->left != nullptr) {
        delete this->left;
    }

    this->left = left;
    left->setParentNode(this);
}

void BinaryOperator::setRight(Expression* right) {
    if (this->right != nullptr) {
        delete this->right;
    }

    this->right = right;
    right->setParentNode(this);
}

/* Getters */
Expression* BinaryOperator::getLeft() {
    return left;
}

Expression* BinaryOperator::getRight() {
    return right;
}

/* Visitors */
void BinaryOperator::accept(Visitor* visitor) {
    visitor->visit(this);
}

