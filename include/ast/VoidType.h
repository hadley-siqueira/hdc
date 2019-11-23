#ifndef HDC_VOID_TYPE_H
#define HDC_VOID_TYPE_H

#include "token/Token.h"
#include "PrimitiveType.h"

namespace hdc {
    class VoidType : public PrimitiveType {
        private:
            Token token;

        public:
            VoidType();
            VoidType(Token& token);

        public:
            Type* clone();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
