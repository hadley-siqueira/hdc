#ifndef HDC_BITWISEXOR_EXPRESSION_H
#define HDC_BITWISEXOR_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class BitwiseXorExpression : public BinaryOperator {
        /* Constructors */
        public:
            BitwiseXorExpression();
            BitwiseXorExpression(Expression* left, Expression* right);
            BitwiseXorExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~BitwiseXorExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
