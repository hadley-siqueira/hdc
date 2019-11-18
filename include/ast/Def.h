#ifndef HDC_DEF_H
#define HDC_DEF_H

#include <vector>

#include "token/Token.h"

#include "ast/ASTNode.h"
#include "ast/Class.h"
#include "ast/Type.h"
#include "ast/LocalVariable.h"
#include "ast/Parameter.h"
#include "ast/Statement.h"
#include "ast/CompoundStatement.h"

#include "symtab/SymbolTable.h"

namespace hdc {
    class Class;
    class SourceFile;
    class SymbolTable;

    class Def : public ASTNode {
        public:
            Def();
            ~Def();

        /* Setters */
        public:
            void setName(hdc::Token name);
            void setClass(hdc::Class* klass);
            void setFile(hdc::SourceFile* file);
            void setReturnType(Type* type);
            void setStatements(CompoundStatement* statements);
            void setSymbolTable(SymbolTable* value);

        /* Getters */
        public:
            std::string getName();
            SymbolTable* getSymbolTable() const;
            Parameter* getParameter(int i);
            Type* getReturnType();
            CompoundStatement* getStatements();

            void addParameter(hdc::Token& name, Type* type);
            int n_parameters();

        public:
            void addLocalVariable(LocalVariable* variable);

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);

        private:
            hdc::Token name;
            hdc::Class* klass;
            hdc::SourceFile* file;
            hdc::Type* return_type;
            std::vector<Parameter*> parameters;
            std::vector<LocalVariable*> localVariables;
            CompoundStatement* statements;
            SymbolTable* symbolTable;
    };
}

#endif
