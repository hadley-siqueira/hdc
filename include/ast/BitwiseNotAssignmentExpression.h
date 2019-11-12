#ifndef HDC_BITWISENOTASSIGNMENT_EXPRESSION_H
#define HDC_BITWISENOTASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class BitwiseNotAssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            BitwiseNotAssignmentExpression();
            BitwiseNotAssignmentExpression(Expression* left, Expression* right);
            BitwiseNotAssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~BitwiseNotAssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
