#ifndef HDC_BINARY_OPERATOR_H
#define HDC_BINARY_OPERATOR_H

#include "token/Token.h"
#include "Expression.h"

namespace hdc {
    class BinaryOperator : public Expression {
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
            void setLeft(Expression* left);
            void setRight(Expression* right);
            void setOper(const Token &value);

        /* Getters */
        public:
            Expression* getLeft();
            Expression* getRight();
            Token getOper() const;

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);            

    protected:
            Expression* left;
            Expression* right;
            Token oper;
    };
}

#endif
