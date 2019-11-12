#ifndef HDC_PLUS_EXPRESSION_H
#define HDC_PLUS_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class PlusExpression : public BinaryOperator {
        /* Constructors */
        public:
            PlusExpression();
            PlusExpression(Expression* left, Expression* right);
            PlusExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~PlusExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
