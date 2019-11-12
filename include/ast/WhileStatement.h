#ifndef HDC_WHILE_STATEMENT_H
#define HDC_WHILE_STATEMENT_H

#include "ast/Statement.h"
#include "ast/CompoundStatement.h"
#include "ast/Expression.h"

namespace hdc {
    class WhileStatement : public Statement {
        public:
            WhileStatement();
            WhileStatement(Expression* expression, CompoundStatement* statements);

            virtual ~WhileStatement();

        /* Getters */
        public:
            Expression* get_expression();
            CompoundStatement* get_statements();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);

        private:
            Expression* expression;
            CompoundStatement* statements;
    };
}

#endif
