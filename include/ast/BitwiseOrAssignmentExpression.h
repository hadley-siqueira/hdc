#ifndef HDC_BITWISEORASSIGNMENT_EXPRESSION_H
#define HDC_BITWISEORASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class BitwiseOrAssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            BitwiseOrAssignmentExpression();
            BitwiseOrAssignmentExpression(Expression* left, Expression* right);
            BitwiseOrAssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~BitwiseOrAssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
