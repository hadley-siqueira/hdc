#ifndef HDC_LOGICALNOT_EXPRESSION_H
#define HDC_LOGICALNOT_EXPRESSION_H

#include "UnaryOperator.h"

namespace hdc {
    class LogicalNotExpression : public UnaryOperator {
        /* Constructors */
        public:
            LogicalNotExpression();
            LogicalNotExpression(Expression* expression);
            LogicalNotExpression(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~LogicalNotExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
