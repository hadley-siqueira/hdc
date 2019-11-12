#ifndef HDC_MINUSASSIGNMENT_EXPRESSION_H
#define HDC_MINUSASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class MinusAssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            MinusAssignmentExpression();
            MinusAssignmentExpression(Expression* left, Expression* right);
            MinusAssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~MinusAssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
