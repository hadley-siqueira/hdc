#ifndef HDC_DOLAR_EXPRESSION_H
#define HDC_DOLAR_EXPRESSION_H

#include "UnaryOperator.h"

namespace hdc {
    class DolarExpression : public UnaryOperator {
        /* Constructors */
        public:
            DolarExpression();
            DolarExpression(Expression* expression);
            DolarExpression(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~DolarExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
