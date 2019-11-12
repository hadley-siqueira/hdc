#ifndef HDC_ADDRESSOF_EXPRESSION_H
#define HDC_ADDRESSOF_EXPRESSION_H

#include "UnaryOperator.h"

namespace hdc {
    class AddressOfExpression : public UnaryOperator {
        /* Constructors */
        public:
            AddressOfExpression();
            AddressOfExpression(Expression* expression);
            AddressOfExpression(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~AddressOfExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
