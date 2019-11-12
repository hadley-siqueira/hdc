#ifndef HDC_SRAASSIGNMENT_EXPRESSION_H
#define HDC_SRAASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class SraAssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            SraAssignmentExpression();
            SraAssignmentExpression(Expression* left, Expression* right);
            SraAssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~SraAssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
