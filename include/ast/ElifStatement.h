#ifndef HDC_ELIF_STATEMENT_H
#define HDC_ELIF_STATEMENT_H

#include "ast/Statement.h"
#include "CompoundStatement.h"
#include "ast/ElseStatement.h"
#include "ast/Expression.h"
#include "symtab/SymbolTable.h"

namespace hdc {
    class SymbolTable;

    class ElifStatement : public Statement {
        /* Constructors */
        public:
            ElifStatement(Expression* expression, CompoundStatement* statements);
            ElifStatement(Expression* expression, CompoundStatement* statements, ElifStatement* elifStatement);
            ElifStatement(Expression* expression, CompoundStatement* statements, ElseStatement* elseStatement);

        /* Destructors */
        public:
            ~ElifStatement();

            ElifStatement* getElifStatement() const;
            void setElifStatement(ElifStatement* value);

            ElseStatement* getElseStatement() const;
            void setElseStatement(ElseStatement* value);

            CompoundStatement* getStatements() const;
            void setStatements(CompoundStatement* value);

            Expression* getExpression() const;
            void setExpression(Expression* value);

            SymbolTable* getSymbolTable() const;
            void setSymbolTable(SymbolTable* value);

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);

        private:
            ElifStatement* elifStatement;
            ElseStatement* elseStatement;
            CompoundStatement* statements;
            Expression* expression;
            SymbolTable* symbolTable;
    };
}

#endif
