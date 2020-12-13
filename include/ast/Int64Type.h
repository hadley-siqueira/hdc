#ifndef HDC_INT64_TYPE_H
#define HDC_INT64_TYPE_H

#include "token/Token.h"
#include "ast/PrimitiveType.h"

namespace hdc {
    class Int64Type : public PrimitiveType {
        private:
            Token token;

        public:
            Int64Type();
            Int64Type(Token& token);

        public:
            Type* clone();
            int getRank();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
