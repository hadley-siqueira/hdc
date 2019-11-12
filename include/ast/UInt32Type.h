#ifndef HDC_UINT32_TYPE_H
#define HDC_UINT32_TYPE_H

#include "token/Token.h"
#include "ast/PrimitiveType.h"

namespace hdc {
    class UInt32Type : public PrimitiveType {
        private:
            Token token;

        public:
            UInt32Type();
            UInt32Type(Token& token);

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
