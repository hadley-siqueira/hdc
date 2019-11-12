#ifndef HDC_DIVISIONASSIGNMENT_EXPRESSION_H
#define HDC_DIVISIONASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class DivisionAssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            DivisionAssignmentExpression();
            DivisionAssignmentExpression(Expression* left, Expression* right);
            DivisionAssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~DivisionAssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
