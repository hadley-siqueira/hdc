#ifndef COMPOUND_STATEMENT_H
#define COMPOUND_STATEMENT_H

#include <vector>

#include "Statement.h"

namespace hdc {
    class CompoundStatement : public Statement {
        private:
            std::vector<Statement*> statements;

        public:
            virtual ~CompoundStatement();

        public:
            void add_statement(Statement* statement);

            int n_statements();

        /* Getters */
        public:
            Statement* get_statement(int i);

        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
