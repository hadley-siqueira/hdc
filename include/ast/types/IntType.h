#ifndef HDC_INT_TYPE_H
#define HDC_INT_TYPE_H

#include "token/Token.h"
#include "ast/types/PrimitiveType.h"


namespace hdc {
    class IntType : public PrimitiveType {
        private:
            Token token;

        public:
            IntType();
            IntType(Token& token);

        public:
            Type* clone();
            int getRank();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
