#ifndef HDC_MODULO_EXPRESSION_H
#define HDC_MODULO_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class ModuloExpression : public BinaryOperator {
        /* Constructors */
        public:
            ModuloExpression();
            ModuloExpression(Expression* left, Expression* right);
            ModuloExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~ModuloExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
