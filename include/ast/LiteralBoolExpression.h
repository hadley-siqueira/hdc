#ifndef HDC_LITERAL_BOOL_H
#define HDC_LITERAL_BOOL_H

#include "LiteralExpression.h"

namespace hdc {
    class LiteralBoolExpression : public LiteralExpression {
        public:
            LiteralBoolExpression();
            LiteralBoolExpression(Token token);

        public:
            virtual ~LiteralBoolExpression();


        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
