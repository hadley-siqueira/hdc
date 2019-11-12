#ifndef HDC_SHIFTRIGHTARITHMETIC_EXPRESSION_H
#define HDC_SHIFTRIGHTARITHMETIC_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class ShiftRightArithmeticExpression : public BinaryOperator {
        /* Constructors */
        public:
            ShiftRightArithmeticExpression();
            ShiftRightArithmeticExpression(Expression* left, Expression* right);
            ShiftRightArithmeticExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~ShiftRightArithmeticExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
