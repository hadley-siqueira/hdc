#ifndef HDC_LOGICALOREXPRESSION_H
#define HDC_LOGICALOREXPRESSION_H

#include "ast/BinaryOperator.h"

namespace hdc {
    class LogicalOrExpression : public BinaryOperator {
        /* Constructors */
        public:
            LogicalOrExpression();
            LogicalOrExpression(Expression* left, Expression* right);
            LogicalOrExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~LogicalOrExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
