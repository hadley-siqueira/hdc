#ifndef HDC_AT_EXPRESSION_H
#define HDC_AT_EXPRESSION_H

#include "UnaryOperator.h"

namespace hdc {
    class AtExpression : public UnaryOperator {
        /* Constructors */
        public:
            AtExpression();
            AtExpression(Expression* expression);
            AtExpression(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~AtExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
