#ifndef HDC_LITERAL_FLOAT_H
#define HDC_LITERAL_FLOAT_H

#include "LiteralExpression.h"

namespace hdc {
    class LiteralFloatExpression : public LiteralExpression {
        public:
            LiteralFloatExpression();
            LiteralFloatExpression(Token token);

        public:
            virtual ~LiteralFloatExpression();


        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
