#ifndef HDC_EXCLUSIVE_RANGE_EXPRESSION_H
#define HDC_EXCLUSIVE_RANGE_EXPRESSION_H

#include "ast/BinaryOperator.h"

namespace hdc {
    class ExclusiveRangeExpression : public BinaryOperator {
        /* Constructors */
        public:
            ExclusiveRangeExpression();
            ExclusiveRangeExpression(Expression* left, Expression* right);
            ExclusiveRangeExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~ExclusiveRangeExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
