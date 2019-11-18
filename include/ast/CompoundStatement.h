#ifndef COMPOUND_STATEMENT_H
#define COMPOUND_STATEMENT_H

#include <vector>

#include "ast/Statement.h"

namespace hdc {
    class CompoundStatement : public Statement {
        private:
            std::vector<Statement*> statements;

        public:
            virtual ~CompoundStatement();

        public:
            void addStatement(Statement* statement);

            int n_statements();

        /* Getters */
        public:
            Statement* getStatement(int i);

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
