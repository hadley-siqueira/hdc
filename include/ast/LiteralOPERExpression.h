#ifndef HDC_LITERAL_OPERH_H
#define HDC_LITERAL_OPERH_H

#include "LiteralExpression.h"

namespace hdc {
    class LiteralOPERExpression : public LiteralExpression {
        public:
            LiteralOPERExpression();
            LiteralOPERExpression(Token token);

        public:
            virtual ~LiteralOPERExpression();


        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
