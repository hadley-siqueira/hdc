#ifndef HDC_UINT64_TYPE_H
#define HDC_UINT64_TYPE_H

#include "token/Token.h"
#include "ast/types/PrimitiveType.h"

namespace hdc {
    class UInt64Type : public PrimitiveType {
        private:
            Token token;

        public:
            UInt64Type();
            UInt64Type(Token& token);

        public:
            Type* clone();
            int getRank();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
