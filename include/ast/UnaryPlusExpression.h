#ifndef HDC_UNARYPLUS_EXPRESSION_H
#define HDC_UNARYPLUS_EXPRESSION_H

#include "UnaryOperator.h"

namespace hdc {
    class UnaryPlusExpression : public UnaryOperator {
        /* Constructors */
        public:
            UnaryPlusExpression();
            UnaryPlusExpression(Expression* expression);
            UnaryPlusExpression(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~UnaryPlusExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
