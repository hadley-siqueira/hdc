#ifndef HDC_DEREFERENCE_EXPRESSION_H
#define HDC_DEREFERENCE_EXPRESSION_H

#include "UnaryOperator.h"

namespace hdc {
    class DereferenceExpression : public UnaryOperator {
        /* Constructors */
        public:
            DereferenceExpression();
            DereferenceExpression(Expression* expression);
            DereferenceExpression(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~DereferenceExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
