#ifndef HDC_UINT16_TYPE_H
#define HDC_UINT16_TYPE_H

#include "token/Token.h"
#include "ast/PrimitiveType.h"

namespace hdc {
    class UInt16Type : public PrimitiveType {
        private:
            Token token;

        public:
            UInt16Type();
            UInt16Type(Token& token);

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
