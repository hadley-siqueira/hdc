#ifndef HDC_SHIFTLEFTLOGICAL_EXPRESSION_H
#define HDC_SHIFTLEFTLOGICAL_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class ShiftLeftLogicalExpression : public BinaryOperator {
        /* Constructors */
        public:
            ShiftLeftLogicalExpression();
            ShiftLeftLogicalExpression(Expression* left, Expression* right);
            ShiftLeftLogicalExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~ShiftLeftLogicalExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
