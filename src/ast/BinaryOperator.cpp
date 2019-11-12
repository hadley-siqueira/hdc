#include "ast/BinaryOperator.h"

using namespace hdc;

/* Constructors */
BinaryOperator::BinaryOperator() {
    left = NULL;
    right = NULL;
}

BinaryOperator::BinaryOperator(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
}

BinaryOperator::BinaryOperator(Token& oper, Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
    this->oper = oper;
}


/* Destructors */
BinaryOperator::~BinaryOperator() {
    delete left;
    delete right;
}

/* Setters */
void BinaryOperator::setLeft(Expression* left) {
    if (this->left != NULL) {
        delete this->left;
    }

    this->left = left;
}

void BinaryOperator::setRight(Expression* right) {
    if (this->right != NULL) {
        delete this->right;
    }

    this->right = right;
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

