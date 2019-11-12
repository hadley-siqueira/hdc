#ifndef HDC_DIVISION_EXPRESSION_H
#define HDC_DIVISION_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class DivisionExpression : public BinaryOperator {
        /* Constructors */
        public:
            DivisionExpression();
            DivisionExpression(Expression* left, Expression* right);
            DivisionExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~DivisionExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
