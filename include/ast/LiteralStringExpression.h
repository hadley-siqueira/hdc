#ifndef HDC_LITERAL_STRING_H
#define HDC_LITERAL_STRING_H

#include "LiteralExpression.h"

namespace hdc {
    class LiteralStringExpression : public LiteralExpression {
        public:
            LiteralStringExpression();
            LiteralStringExpression(Token token);

        public:
            virtual ~LiteralStringExpression();


        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
