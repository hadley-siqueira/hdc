#ifndef HDC_FOREACH_STATEMENT_H
#define HDC_FOREACH_STATEMENT_H

#include "ast/Statement.h"
#include "ast/CompoundStatement.h"
#include "ast/Expression.h"

namespace hdc {
    class ForEachStatement : public Statement {
        public:
            ForEachStatement(Expression* e1, Expression* e2, CompoundStatement* statements);

        public:
            ~ForEachStatement();

            Expression* getE1() const;
            void setE1(Expression* value);

            Expression* getE2() const;
            void setE2(Expression* value);

            CompoundStatement* getStatements() const;
            void setStatements(CompoundStatement* value);

        public:
            void accept(Visitor* visitor);

        private:
            Expression* e1;
            Expression* e2;
            CompoundStatement* statements;
    };
}

#endif
