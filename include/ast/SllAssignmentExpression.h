#ifndef HDC_SLLASSIGNMENT_EXPRESSION_H
#define HDC_SLLASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class SllAssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            SllAssignmentExpression();
            SllAssignmentExpression(Expression* left, Expression* right);
            SllAssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~SllAssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
