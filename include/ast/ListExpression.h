#ifndef HDC_LIST_EXPRESSION_H
#define HDC_LIST_EXPRESSION_H

#include <vector>

#include "ast/Expression.h"

namespace hdc {
    class ListExpression : public Expression {
        public:
            ListExpression();

        public:
            ~ListExpression();

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
