#ifndef HDC_WHILE_STATEMENT_H
#define HDC_WHILE_STATEMENT_H

#include "ast/Statement.h"
#include "ast/CompoundStatement.h"
#include "ast/Expression.h"
#include "symtab/SymbolTable.h"

namespace hdc {
    class WhileStatement : public Statement {
        public:
            WhileStatement();
            WhileStatement(Expression* expression, CompoundStatement* statements);

            virtual ~WhileStatement();

        /* Getters */
        public:
            Expression* getExpression();
            CompoundStatement* getStatements();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);

            SymbolTable *getSymbolTable() const;
            void setSymbolTable(SymbolTable *value);

    private:
            Expression* expression;
            CompoundStatement* statements;
            SymbolTable* symbolTable;
    };
}

#endif
