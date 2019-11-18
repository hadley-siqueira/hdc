#ifndef HDC_CALL_OPERATOR_H
#define HDC_CALL_OPERATOR_H

#include <vector>

#include "token/Token.h"
#include "Expression.h"

namespace hdc {
    class CallExpression : public Expression {
        protected:
            Token oper;
            Expression* expression;
            std::vector<Expression*> arguments;

        /* Constructors */
        public:
            CallExpression();
            CallExpression(Expression* expression, std::vector<Expression*> arguments);
            CallExpression(Token& oper, Expression* expression, std::vector<Expression*> arguments);

        /* Destructors */
        public:
            virtual ~CallExpression();

        /* Setters */
        public:
            void set_expression(Expression* expression);
            void set_arguments(std::vector<Expression*> arguments);

        /* Getters */
        public:
            Expression* get_expression();
            std::vector<Expression*>& get_arguments();
            Expression* getArgument(int i);
            int n_arguments();

        /* Actions */
        public:
            void add_argument(Expression* expression);

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
