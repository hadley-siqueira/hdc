#ifndef HDC_UOPERH_EXPRESSION_H
#define HDC_UOPERH_EXPRESSION_H

#include "UnaryOperator.h"

namespace hdc {
    class UOPERExpression : public UnaryOperator {
        /* Constructors */
        public:
            UOPERExpression();
            UOPERExpression(Expression* expression);
            UOPERExpression(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~UOPERExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
