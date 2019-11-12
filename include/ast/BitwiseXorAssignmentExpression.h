#ifndef HDC_BITWISEXORASSIGNMENT_EXPRESSION_H
#define HDC_BITWISEXORASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class BitwiseXorAssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            BitwiseXorAssignmentExpression();
            BitwiseXorAssignmentExpression(Expression* left, Expression* right);
            BitwiseXorAssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~BitwiseXorAssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
