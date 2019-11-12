#ifndef HDC_MODULOASSIGNMENT_EXPRESSION_H
#define HDC_MODULOASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class ModuloAssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            ModuloAssignmentExpression();
            ModuloAssignmentExpression(Expression* left, Expression* right);
            ModuloAssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~ModuloAssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
