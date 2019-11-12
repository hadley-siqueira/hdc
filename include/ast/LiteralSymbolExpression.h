#ifndef HDC_LITERAL_SYMBOL_H
#define HDC_LITERAL_SYMBOL_H

#include "LiteralExpression.h"

namespace hdc {
    class LiteralSymbolExpression : public LiteralExpression {
        public:
            LiteralSymbolExpression();
            LiteralSymbolExpression(Token token);

        public:
            virtual ~LiteralSymbolExpression();


        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
