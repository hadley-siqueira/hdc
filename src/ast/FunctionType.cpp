#include "ast/FunctionType.h"

using namespace hdc;

FunctionType::FunctionType() {

}

FunctionType::~FunctionType() {
    for (int i = 0; i < subtypes.size(); ++i) {
        delete subtypes[i];
    }
}

void FunctionType::add(Type *type) {
    subtypes.push_back(type);
}

Type *FunctionType::getType(int i) {
    if (i < subtypes.size()) {
        return subtypes[i];
    }

    return nullptr;
}

Type *FunctionType::getParameter(int i) {
    if (i < subtypes.size() - 1) {
        return subtypes[i];
    }

    return nullptr;
}

Type *FunctionType::getReturnType() {
    auto size = subtypes.size();

    if (size > 0) {
        return subtypes[size - 1];
    }

    return nullptr;
}

int FunctionType::n_types() {
    return subtypes.size();
}

int FunctionType::n_parameters() {
    return subtypes.size() - 1;
}

Type *FunctionType::clone() {
    FunctionType* cloned = new FunctionType();

    for (int i = 0; i < subtypes.size(); ++i) {
        cloned->subtypes.push_back(subtypes[i]->clone());
    }

    return cloned;
}

bool FunctionType::equals(Type *other) {
    return false;
}

int FunctionType::getRank() {
    return 20;
}

void FunctionType::accept(Visitor *visitor) {
    visitor->visit(this);
}
