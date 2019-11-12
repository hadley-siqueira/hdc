#ifndef HDC_LITERAL_DOUBLE_H
#define HDC_LITERAL_DOUBLE_H

#include "LiteralExpression.h"

namespace hdc {
    class LiteralDoubleExpression : public LiteralExpression {
        public:
            LiteralDoubleExpression();
            LiteralDoubleExpression(Token token);

        public:
            virtual ~LiteralDoubleExpression();


        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
