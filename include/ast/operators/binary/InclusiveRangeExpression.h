#ifndef HDC_INCLUSIVE_RANGE_EXPRESSION_H
#define HDC_INCLUSIVE_RANGE_EXPRESSION_H

#include "ast/BinaryOperator.h"

namespace hdc {
    class InclusiveRangeExpression : public BinaryOperator {
        /* Constructors */
        public:
            InclusiveRangeExpression();
            InclusiveRangeExpression(Expression* left, Expression* right);
            InclusiveRangeExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~InclusiveRangeExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
