#ifndef HDC_IF_STATEMENT_H
#define HDC_IF_STATEMENT_H

#include "ast/Statement.h"
#include "ast/CompoundStatement.h"
#include "ast/ElifStatement.h"
#include "ast/ElseStatement.h"
#include "ast/Expression.h"
#include "symtab/SymbolTable.h"

namespace hdc {
    class ElifStatement;
    class ElseStatement;
    class SymbolTable;

    class IfStatement : public Statement {
        /* Constructors */
        public:
            IfStatement(Expression* expression, CompoundStatement* statements);
            IfStatement(Expression* expression, CompoundStatement* statements, ElifStatement* elifStatement);
            IfStatement(Expression* expression, CompoundStatement* statements, ElseStatement* elseStatement);

        /* Destructors */
        public:
            ~IfStatement();

        public:
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
