#ifndef HDC_SPECIALASSIGNMENT_EXPRESSION_H
#define HDC_SPECIALASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class SpecialAssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            SpecialAssignmentExpression();
            SpecialAssignmentExpression(Expression* left, Expression* right);
            SpecialAssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~SpecialAssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
