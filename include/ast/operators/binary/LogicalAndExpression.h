#ifndef HDC_LOGICALANDEXPRESSION_H
#define HDC_LOGICALANDEXPRESSION_H

#include "ast/BinaryOperator.h"

namespace hdc {
    class LogicalAndExpression : public BinaryOperator {
        /* Constructors */
        public:
            LogicalAndExpression();
            LogicalAndExpression(Expression* left, Expression* right);
            LogicalAndExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~LogicalAndExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
