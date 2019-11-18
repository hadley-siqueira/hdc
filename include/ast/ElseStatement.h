#ifndef HDC_ELSE_STATEMENT_H
#define HDC_ELSE_STATEMENT_H

#include "ast/Statement.h"
#include "ast/CompoundStatement.h"
#include "symtab/SymbolTable.h"

namespace hdc {
    class SymbolTable;

    class ElseStatement : public Statement {
        /* Constructors */
        public:
            ElseStatement(CompoundStatement* statements);

        /* Destructors */
        public:
            ~ElseStatement();

        public:
            CompoundStatement* getStatements();
            void setStatements(CompoundStatement* value);

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);

            SymbolTable* getSymbolTable() const;
            void setSymbolTable(SymbolTable* value);

        private:
            CompoundStatement* statements;
            SymbolTable* symbolTable;
    };
}

#endif
