#ifndef HDC_INT16_TYPE_H
#define HDC_INT16_TYPE_H

#include "token/Token.h"
#include "ast/types/PrimitiveType.h"

namespace hdc {
    class Int16Type : public PrimitiveType {
        private:
            Token token;

        public:
            Int16Type();
            Int16Type(Token& token);

        public:
            Type* clone();
            int getRank();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
