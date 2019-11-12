#ifndef HDC_GREATERTHANOREQUAL_EXPRESSION_H
#define HDC_GREATERTHANOREQUAL_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class GreaterThanOrEqualExpression : public BinaryOperator {
        /* Constructors */
        public:
            GreaterThanOrEqualExpression();
            GreaterThanOrEqualExpression(Expression* left, Expression* right);
            GreaterThanOrEqualExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~GreaterThanOrEqualExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
