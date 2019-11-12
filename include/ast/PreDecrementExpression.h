#ifndef HDC_PREDECREMENT_EXPRESSION_H
#define HDC_PREDECREMENT_EXPRESSION_H

#include "UnaryOperator.h"

namespace hdc {
    class PreDecrementExpression : public UnaryOperator {
        /* Constructors */
        public:
            PreDecrementExpression();
            PreDecrementExpression(Expression* expression);
            PreDecrementExpression(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~PreDecrementExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
