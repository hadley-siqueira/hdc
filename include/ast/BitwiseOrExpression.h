#ifndef HDC_BITWISEOR_EXPRESSION_H
#define HDC_BITWISEOR_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class BitwiseOrExpression : public BinaryOperator {
        /* Constructors */
        public:
            BitwiseOrExpression();
            BitwiseOrExpression(Expression* left, Expression* right);
            BitwiseOrExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~BitwiseOrExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
