#ifndef HDC_PREINCREMENT_EXPRESSION_H
#define HDC_PREINCREMENT_EXPRESSION_H

#include "UnaryOperator.h"

namespace hdc {
    class PreIncrementExpression : public UnaryOperator {
        /* Constructors */
        public:
            PreIncrementExpression();
            PreIncrementExpression(Expression* expression);
            PreIncrementExpression(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~PreIncrementExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
