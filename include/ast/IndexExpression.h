#ifndef HDC_INDEX_EXPRESSION_H
#define HDC_INDEX_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class IndexExpression : public BinaryOperator {
        /* Constructors */
        public:
            IndexExpression();
            IndexExpression(Expression* left, Expression* right);
            IndexExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~IndexExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
