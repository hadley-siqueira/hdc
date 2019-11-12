#ifndef HDC_PLUSASSIGNMENT_EXPRESSION_H
#define HDC_PLUSASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class PlusAssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            PlusAssignmentExpression();
            PlusAssignmentExpression(Expression* left, Expression* right);
            PlusAssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~PlusAssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
