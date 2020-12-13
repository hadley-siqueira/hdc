#ifndef HDC_NAMED_TYPE_H
#define HDC_NAMED_TYPE_H

#include "ast/IdentifierExpression.h"
#include "ast/Type.h"

namespace hdc {
    class NamedType : public Type {
        public:
            NamedType();
            NamedType(IdentifierExpression* name);

        public:
            ~NamedType();

        public:
            Type* clone();
            int getRank();

        public:
            void accept(Visitor* visitor);

            IdentifierExpression* getName() const;
            void setName(IdentifierExpression* value);

        private:
            IdentifierExpression* name;
    };
}

#endif
