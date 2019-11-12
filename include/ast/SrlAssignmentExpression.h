#ifndef HDC_SRLASSIGNMENT_EXPRESSION_H
#define HDC_SRLASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class SrlAssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            SrlAssignmentExpression();
            SrlAssignmentExpression(Expression* left, Expression* right);
            SrlAssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~SrlAssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
