#ifndef HDC_CHAR_TYPE_H
#define HDC_CHAR_TYPE_H

#include "token/Token.h"
#include "PrimitiveType.h"

namespace hdc {
    class CharType : public PrimitiveType {
        private:
            Token token;

        public:
            CharType();
            CharType(Token& token);

        public:
            Type* clone();
            int getRank();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
