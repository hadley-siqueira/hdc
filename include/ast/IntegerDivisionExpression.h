#ifndef HDC_INTEGERDIVISION_EXPRESSION_H
#define HDC_INTEGERDIVISION_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class IntegerDivisionExpression : public BinaryOperator {
        /* Constructors */
        public:
            IntegerDivisionExpression();
            IntegerDivisionExpression(Expression* left, Expression* right);
            IntegerDivisionExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~IntegerDivisionExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
