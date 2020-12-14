#ifndef HDC_LITERAL_NULL_H
#define HDC_LITERAL_NULL_H

#include "LiteralExpression.h"

namespace hdc {
    class LiteralNullExpression : public LiteralExpression {
        public:
            LiteralNullExpression();
            LiteralNullExpression(Token token);

        public:
            virtual ~LiteralNullExpression();


        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
