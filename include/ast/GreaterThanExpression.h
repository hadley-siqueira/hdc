#ifndef HDC_GREATERTHAN_EXPRESSION_H
#define HDC_GREATERTHAN_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class GreaterThanExpression : public BinaryOperator {
        /* Constructors */
        public:
            GreaterThanExpression();
            GreaterThanExpression(Expression* left, Expression* right);
            GreaterThanExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~GreaterThanExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
