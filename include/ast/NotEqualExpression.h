#ifndef HDC_NOTEQUAL_EXPRESSION_H
#define HDC_NOTEQUAL_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class NotEqualExpression : public BinaryOperator {
        /* Constructors */
        public:
            NotEqualExpression();
            NotEqualExpression(Expression* left, Expression* right);
            NotEqualExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~NotEqualExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
