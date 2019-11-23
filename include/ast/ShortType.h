#ifndef HDC_SHORT_TYPE_H
#define HDC_SHORT_TYPE_H

#include "token/Token.h"
#include "PrimitiveType.h"

namespace hdc {
    class ShortType : public PrimitiveType {
        private:
            Token token;

        public:
            ShortType();
            ShortType(Token& token);

        public:
            Type* clone();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
