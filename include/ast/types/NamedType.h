#ifndef HDC_NAMED_TYPE_H
#define HDC_NAMED_TYPE_H

#include "ast/IdentifierExpression.h"
#include "ast/types/Type.h"

namespace hdc {
    class NamedType : public Type {
        public:
            NamedType();
            NamedType(IdentifierExpression* name);

        public:
            ~NamedType();

        public:
            Type* clone();
            bool equals(Type *other);
            int getRank();

            void setDescriptor(Class* klass);
            void setDescriptor(Struct* st);
            void* getDescriptor();
            SymbolTable* getSymbolTable();

        public:
            void accept(Visitor* visitor);

            IdentifierExpression* getName() const;
            void setName(IdentifierExpression* value);

        private:
            IdentifierExpression* name;
            Class* classDescriptor;
            Struct* structDescriptor;
    };
}

#endif
