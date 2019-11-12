#ifndef HDC_DOUBLE_TYPE_H
#define HDC_DOUBLE_TYPE_H

#include "token/Token.h"
#include "PrimitiveType.h"

namespace hdc {
    class DoubleType : public PrimitiveType {
        private:
            Token token;

        public:
            DoubleType();
            DoubleType(Token& token);

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
