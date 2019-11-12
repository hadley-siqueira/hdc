#ifndef HDC_LESSTHAN_EXPRESSION_H
#define HDC_LESSTHAN_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class LessThanExpression : public BinaryOperator {
        /* Constructors */
        public:
            LessThanExpression();
            LessThanExpression(Expression* left, Expression* right);
            LessThanExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~LessThanExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
