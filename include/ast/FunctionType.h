#ifndef HDC_FUNCTIONTYPE_H
#define HDC_FUNCTIONTYPE_H

#include <vector>

#include "ast/Type.h"

namespace hdc {
    class FunctionType : public Type {
    public:
        FunctionType();
        ~FunctionType();

    public:
        void add(Type* type);

        Type* getType(int i);
        Type* getParameter(int i);
        Type* getReturnType();

        int n_types();
        int n_parameters();

    public:
        Type* clone();
        bool equals(Type* other);
        int getRank();

    public:
        void accept(Visitor* visitor);

    private:
        std::vector<Type*> subtypes;
    };
}

#endif // FUNCTIONTYPE_H
