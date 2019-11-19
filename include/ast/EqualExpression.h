#ifndef HDC_EQUAL_EXPRESSION_H
#define HDC_EQUAL_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class EqualExpression : public BinaryOperator {
        /* Constructors */
        public:
            EqualExpression();
            EqualExpression(Expression* left, Expression* right);
            EqualExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~EqualExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
