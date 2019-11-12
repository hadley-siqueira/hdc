#ifndef HDC_UNARY_OPERATOR_H
#define HDC_UNARY_OPERATOR_H

#include "token/Token.h"
#include "Expression.h"


namespace hdc {
    class UnaryOperator : public Expression {
        protected:
            Expression* expression;
            Token oper;

        /* Constructors */
        public:
            UnaryOperator();
            UnaryOperator(Expression* expression);
            UnaryOperator(Token& oper, Expression* expression);

        /* Destructors */
        virtual ~UnaryOperator();

        /* Setters */
        public:
            void set_expression(Expression* left);

        /* Getters */
        public:
            Expression* get_expression();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
