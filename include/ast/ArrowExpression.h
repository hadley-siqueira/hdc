#ifndef HDC_ARROW_EXPRESSION_H
#define HDC_ARROW_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class ArrowExpression : public BinaryOperator {
        /* Constructors */
        public:
            ArrowExpression();
            ArrowExpression(Expression* left, Expression* right);
            ArrowExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~ArrowExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
