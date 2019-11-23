#ifndef HDC_INT32_TYPE_H
#define HDC_INT32_TYPE_H

#include "token/Token.h"
#include "ast/PrimitiveType.h"

namespace hdc {
    class Int32Type : public PrimitiveType {
        private:
            Token token;

        public:
            Int32Type();
            Int32Type(Token& token);

        public:
            Type* clone();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
