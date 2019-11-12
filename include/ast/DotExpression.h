#ifndef HDC_DOT_EXPRESSION_H
#define HDC_DOT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class DotExpression : public BinaryOperator {
        /* Constructors */
        public:
            DotExpression();
            DotExpression(Expression* left, Expression* right);
            DotExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~DotExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
