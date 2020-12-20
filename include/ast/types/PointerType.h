#ifndef POINTER_TYPE_H
#define POINTER_TYPE_H

#include "token/Token.h"
#include "ast/types/Type.h"

namespace hdc {
    class PointerType : public Type {
        public:
            PointerType();
            PointerType(Type* type);
            PointerType(Type* type, Token& token);

            virtual ~PointerType();

        /* Setters */
        public:
            void setSubtype(Type* type);

        /* Getters */
        public:
            Type* getSubtype();

        public:
            Type* clone();
            bool equals(Type* other);
            int getRank();

        public:
            virtual void accept(Visitor* visitor);

        private:
            Type* subtype;
            Token token;

    };
}

#endif
