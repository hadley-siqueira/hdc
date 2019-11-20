#ifndef POINTER_TYPE_H
#define POINTER_TYPE_H

#include "token/Token.h"
#include "ast/Type.h"

namespace hdc {
    class PointerType : public Type {
        private:
            Type* subtype;
            Token token;

        public:
            PointerType();
            PointerType(Type* type, Token& token);

            virtual ~PointerType();

            Type* getSubtype();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
