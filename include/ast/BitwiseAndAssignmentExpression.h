#ifndef HDC_BITWISEANDASSIGNMENT_EXPRESSION_H
#define HDC_BITWISEANDASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class BitwiseAndAssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            BitwiseAndAssignmentExpression();
            BitwiseAndAssignmentExpression(Expression* left, Expression* right);
            BitwiseAndAssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~BitwiseAndAssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
