#ifndef HDC_INT8_TYPE_H
#define HDC_INT8_TYPE_H

#include "token/Token.h"
#include "PrimitiveType.h"

namespace hdc {
    class Int8Type : public PrimitiveType {
        private:
            Token token;

        public:
            Int8Type();
            Int8Type(Token& token);

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
