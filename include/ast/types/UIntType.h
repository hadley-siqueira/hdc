#ifndef HDC_UINT_TYPE_H
#define HDC_UINT_TYPE_H

#include "token/Token.h"
#include "ast/types/PrimitiveType.h"

namespace hdc {
    class UIntType : public PrimitiveType {
        private:
            Token token;

        public:
            UIntType();
            UIntType(Token& token);

        public:
            Type* clone();
            int getRank();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
