#ifndef HDC_BINARY_OPERATOR_H
#define HDC_BINARY_OPERATOR_H

#include "token/Token.h"
#include "Expression.h"

namespace hdc {
    class BinaryOperator : public Expression {
        protected:
            Expression* left;
            Expression* right;
            Token oper;
            

        /* Constructors */
        public:
            BinaryOperator();
            BinaryOperator(Expression* left, Expression* right);
            BinaryOperator(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        public:
            virtual ~BinaryOperator();

        /* Setters */
        public:
            void set_left(Expression* left);
            void set_right(Expression* right);

        /* Getters */
        public:
            Expression* get_left();
            Expression* get_right();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
