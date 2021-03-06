#ifndef HDC_FLOAT_TYPE_H
#define HDC_FLOAT_TYPE_H

#include "token/Token.h"
#include "ast/types/PrimitiveType.h"

namespace hdc {
    class FloatType : public PrimitiveType {
        private:
            Token token;

        public:
            FloatType();
            FloatType(Token& token);

        public:
            Type* clone();
            int getRank();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
