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
            std::string getUniqueCppName();
            SymbolTable* getSymbolTable() const;
            Parameter* getParameter(int i);
            LocalVariable* getLocalVariable(int i);
            Type* getReturnType();
            CompoundStatement* getStatements();
            int getLine();
            int getColumn();
            Class* getClass();
            bool isMethod();

            void addParameter(hdc::Token& name, Type* type);
            int n_parameters();
            int n_local_variables();

        public:
            void addLocalVariable(LocalVariable* variable);

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);

            int getId() const;
            void setId(int value);

            int getGlobalId() const;
            void setGlobalId(int value);

    private:
            hdc::Token name;
            hdc::Class* klass;
            hdc::SourceFile* file;
            hdc::Type* return_type;
            std::vector<Parameter*> parameters;
            std::vector<LocalVariable*> localVariables;
            CompoundStatement* statements;
            SymbolTable* symbolTable;
            int localVarNameCounter;
            int id;
            int globald;
    };
}

#endif
