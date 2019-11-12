#ifndef HDC_LONG_TYPE_H
#define HDC_LONG_TYPE_H

#include "token/Token.h"
#include "PrimitiveType.h"

namespace hdc {
    class LongType : public PrimitiveType {
        private:
            Token token;

        public:
            LongType();
            LongType(Token& token);

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
