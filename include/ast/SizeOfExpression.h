#ifndef HDC_SIZEOF_EXPRESSION_H
#define HDC_SIZEOF_EXPRESSION_H

#include "UnaryOperator.h"

namespace hdc {
    class SizeOfExpression : public UnaryOperator {
        /* Constructors */
        public:
            SizeOfExpression();
            SizeOfExpression(Expression* expression);
            SizeOfExpression(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~SizeOfExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
