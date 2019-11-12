#ifndef HDC_PARENTHESIS_EXPRESSION_H
#define HDC_PARENTHESIS_EXPRESSION_H

#include "UnaryOperator.h"

namespace hdc {
    class ParenthesisExpression : public UnaryOperator {
        /* Constructors */
        public:
            ParenthesisExpression();
            ParenthesisExpression(Expression* expression);
            ParenthesisExpression(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~ParenthesisExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
