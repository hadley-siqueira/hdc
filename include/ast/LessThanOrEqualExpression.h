#ifndef HDC_LESSTHANOREQUAL_EXPRESSION_H
#define HDC_LESSTHANOREQUAL_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class LessThanOrEqualExpression : public BinaryOperator {
        /* Constructors */
        public:
            LessThanOrEqualExpression();
            LessThanOrEqualExpression(Expression* left, Expression* right);
            LessThanOrEqualExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~LessThanOrEqualExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
