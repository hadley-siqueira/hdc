#ifndef HDC_UCHAR_TYPE_H
#define HDC_UCHAR_TYPE_H

#include "token/Token.h"
#include "PrimitiveType.h"

namespace hdc {
    class UCharType : public PrimitiveType {
        private:
            Token token;

        public:
            UCharType();
            UCharType(Token& token);

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
