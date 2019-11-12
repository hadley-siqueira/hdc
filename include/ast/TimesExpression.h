#ifndef HDC_TIMES_EXPRESSION_H
#define HDC_TIMES_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class TimesExpression : public BinaryOperator {
        /* Constructors */
        public:
            TimesExpression();
            TimesExpression(Expression* left, Expression* right);
            TimesExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~TimesExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
