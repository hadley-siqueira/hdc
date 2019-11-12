#ifndef HDC_SIZEOF_EXPRESSION_H
#define HDC_SIZEOF_EXPRESSION_H

#include "UnaryOperator.h"

namespace hdc {
    class SizeofExpression : public UnaryOperator {
        /* Constructors */
        public:
            SizeofExpression();
            SizeofExpression(Expression* expression);
            SizeofExpression(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~SizeofExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
