#ifndef HDC_BITWISENOT_EXPRESSION_H
#define HDC_BITWISENOT_EXPRESSION_H

#include "UnaryOperator.h"

namespace hdc {
    class BitwiseNotExpression : public UnaryOperator {
        /* Constructors */
        public:
            BitwiseNotExpression();
            BitwiseNotExpression(Expression* expression);
            BitwiseNotExpression(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~BitwiseNotExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
