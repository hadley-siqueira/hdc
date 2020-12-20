#ifndef HDC_UINT16_TYPE_H
#define HDC_UINT16_TYPE_H

#include "token/Token.h"
#include "ast/types/PrimitiveType.h"

namespace hdc {
    class UInt16Type : public PrimitiveType {
        private:
            Token token;

        public:
            UInt16Type();
            UInt16Type(Token& token);

        public:
            Type* clone();
            int getRank();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
