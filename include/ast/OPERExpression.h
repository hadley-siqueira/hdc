#ifndef HDC_OPERH_EXPRESSION_H
#define HDC_OPERH_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class OPERExpression : public BinaryOperator {
        /* Constructors */
        public:
            OPERExpression();
            OPERExpression(Expression* left, Expression* right);
            OPERExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~OPERExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
