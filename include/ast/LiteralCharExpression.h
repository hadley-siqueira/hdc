#ifndef HDC_LITERAL_CHAR_H
#define HDC_LITERAL_CHAR_H

#include "LiteralExpression.h"

namespace hdc {
    class LiteralCharExpression : public LiteralExpression {
        public:
            LiteralCharExpression();
            LiteralCharExpression(Token token);

        public:
            virtual ~LiteralCharExpression();


        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
