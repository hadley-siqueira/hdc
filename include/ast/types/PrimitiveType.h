#ifndef HDC_PRIMITIVE_TYPE
#define HDC_PRIMITIVE_TYPE

#include "token/Token.h"
#include "ast/types/Type.h"

namespace hdc {
    class PrimitiveType : public Type {
        private:
            Token token;

        public:
            PrimitiveType();
            PrimitiveType(Token& token);

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
