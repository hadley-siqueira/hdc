#ifndef HDC_UINT64_TYPE_H
#define HDC_UINT64_TYPE_H

#include "token/Token.h"
#include "ast/PrimitiveType.h"

namespace hdc {
    class UInt64Type : public PrimitiveType {
        private:
            Token token;

        public:
            UInt64Type();
            UInt64Type(Token& token);

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
