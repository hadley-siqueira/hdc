#ifndef HDC_LITERAL_INTEGER_H
#define HDC_LITERAL_INTEGER_H

#include "LiteralExpression.h"

namespace hdc {
    class LiteralIntegerExpression : public LiteralExpression {
        public:
            LiteralIntegerExpression();
            LiteralIntegerExpression(Token token);

        public:
            virtual ~LiteralIntegerExpression();


        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
