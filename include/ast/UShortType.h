#ifndef HDC_USHORT_TYPE_H
#define HDC_USHORT_TYPE_H

#include "token/Token.h"
#include "PrimitiveType.h"

namespace hdc {
    class UShortType : public PrimitiveType {
        private:
            Token token;

        public:
            UShortType();
            UShortType(Token& token);

        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
