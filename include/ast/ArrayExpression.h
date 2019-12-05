#ifndef HDC_ARRAY_EXPRESSION_H
#define HDC_ARRAY_EXPRESSION_H

#include <vector>

#include "ast/Expression.h"

namespace hdc {
    class ArrayExpression : public Expression {
        public:
            ArrayExpression();

        public:
            ~ArrayExpression();

        public:
            void addExpression(Expression* expression);

        public:
            int n_expressions();

        public:
            Expression* getExpression(int i);

        public:
            void accept(Visitor* visitor);

        private:
            std::vector<Expression*> expressions;
    };
}

#endif
