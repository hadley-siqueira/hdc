#ifndef HDC_ULONG_TYPE_H
#define HDC_ULONG_TYPE_H

#include "token/Token.h"
#include "PrimitiveType.h"

namespace hdc {
    class ULongType : public PrimitiveType {
        private:
            Token token;

        public:
            ULongType();
            ULongType(Token& token);

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
