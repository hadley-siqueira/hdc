#ifndef HDC_SHIFTRIGHTLOGICAL_EXPRESSION_H
#define HDC_SHIFTRIGHTLOGICAL_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class ShiftRightLogicalExpression : public BinaryOperator {
        /* Constructors */
        public:
            ShiftRightLogicalExpression();
            ShiftRightLogicalExpression(Expression* left, Expression* right);
            ShiftRightLogicalExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~ShiftRightLogicalExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
