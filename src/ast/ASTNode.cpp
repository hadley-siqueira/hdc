#include <iostream>

#include "ast/ASTNode.h"

using namespace hdc;

ASTNode::ASTNode() {
    parentNode = nullptr;
}

void ASTNode::setKind(hdc::ASTKind kind) {
    this->kind = kind;
}

ASTKind ASTNode::getKind() {
    return kind;
}

ASTNode *ASTNode::getParentNode() const {
    return parentNode;
}

void ASTNode::setParentNode(ASTNode *value) {
    parentNode = value;
}
