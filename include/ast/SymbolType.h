#ifndef HDC_SYMBOL_TYPE_H
#define HDC_SYMBOL_TYPE_H

#include "token/Token.h"
#include "ast/PrimitiveType.h"

namespace hdc {
    class SymbolType : public PrimitiveType {
        private:
            Token token;

        public:
            SymbolType();
            SymbolType(Token& token);

        public:
            Type* clone();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
