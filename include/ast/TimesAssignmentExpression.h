#ifndef HDC_TIMESASSIGNMENT_EXPRESSION_H
#define HDC_TIMESASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class TimesAssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            TimesAssignmentExpression();
            TimesAssignmentExpression(Expression* left, Expression* right);
            TimesAssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~TimesAssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
