#ifndef HDC_BOOL_TYPE_H
#define HDC_BOOL_TYPE_H

#include "token/Token.h"
#include "PrimitiveType.h"

namespace hdc {
    class BoolType : public PrimitiveType {
        private:
            Token token;

        public:
            BoolType();
            BoolType(Token& token);

        public:
            Type* clone();
            int getRank();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
