#ifndef HDC_UINT8_TYPE_H
#define HDC_UINT8_TYPE_H

#include "token/Token.h"
#include "ast/types/PrimitiveType.h"

namespace hdc {
    class UInt8Type : public PrimitiveType {
        private:
            Token token;

        public:
            UInt8Type();
            UInt8Type(Token& token);

        public:
            Type* clone();
            int getRank();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
