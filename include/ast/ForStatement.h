#ifndef HDC_FOR_STATEMENT_H
#define HDC_FOR_STATEMENT_H

#include "ast/Statement.h"
#include "ast/CompoundStatement.h"
#include "ast/Expression.h"

namespace hdc {
    class ForStatement : public Statement {
        public:
            ForStatement(Expression* e1, Expression* e2, Expression* e3, CompoundStatement* statements);

        public:
            ~ForStatement();

            Expression* getE1() const;
            void setE1(Expression* value);

            Expression* getE2() const;
            void setE2(Expression* value);

            Expression* getE3() const;
            void setE3(Expression* value);

            CompoundStatement* getStatements() const;
            void setStatements(CompoundStatement* value);

        public:
            void accept(Visitor* visitor);

        private:
            Expression* e1;
            Expression* e2;
            Expression* e3;
            CompoundStatement* statements;
    };
}

#endif
