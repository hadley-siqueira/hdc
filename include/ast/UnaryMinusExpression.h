#ifndef HDC_UNARYMINUS_EXPRESSION_H
#define HDC_UNARYMINUS_EXPRESSION_H

#include "UnaryOperator.h"

namespace hdc {
    class UnaryMinusExpression : public UnaryOperator {
        /* Constructors */
        public:
            UnaryMinusExpression();
            UnaryMinusExpression(Expression* expression);
            UnaryMinusExpression(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~UnaryMinusExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
