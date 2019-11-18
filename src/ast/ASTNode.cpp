#include "ast/ASTNode.h"

void hdc::ASTNode::setKind(hdc::ASTKind kind) {
    this->kind = kind;
}

hdc::ASTKind hdc::ASTNode::getKind() {
    return kind;
}
