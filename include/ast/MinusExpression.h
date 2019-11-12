#ifndef HDC_MINUS_EXPRESSION_H
#define HDC_MINUS_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class MinusExpression : public BinaryOperator {
        /* Constructors */
        public:
            MinusExpression();
            MinusExpression(Expression* left, Expression* right);
            MinusExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~MinusExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
