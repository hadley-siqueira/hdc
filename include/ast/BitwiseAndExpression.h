#ifndef HDC_BITWISEAND_EXPRESSION_H
#define HDC_BITWISEAND_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class BitwiseAndExpression : public BinaryOperator {
        /* Constructors */
        public:
            BitwiseAndExpression();
            BitwiseAndExpression(Expression* left, Expression* right);
            BitwiseAndExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~BitwiseAndExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
