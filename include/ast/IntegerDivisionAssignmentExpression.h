#ifndef HDC_INTEGERDIVISIONASSIGNMENT_EXPRESSION_H
#define HDC_INTEGERDIVISIONASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class IntegerDivisionAssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            IntegerDivisionAssignmentExpression();
            IntegerDivisionAssignmentExpression(Expression* left, Expression* right);
            IntegerDivisionAssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~IntegerDivisionAssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
