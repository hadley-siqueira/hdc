#ifndef HDC_DEF_H
#define HDC_DEF_H

#include <vector>

#include "token/Token.h"

#include "ast/ASTNode.h"
#include "ast/Class.h"
#include "ast/Type.h"
#include "ast/Parameter.h"

#include "ast/Statement.h"
#include "ast/CompoundStatement.h"

#include "symtab/SymbolTable.h"

namespace hdc {
    class Class;
    class SourceFile;

    class Def : public ASTNode {
        public:
            Def();
            ~Def();

        /* Setters */
        public:
            void set_name(hdc::Token name);
            void set_class(hdc::Class* klass);
            void set_file(hdc::SourceFile* file);
            void set_return_type(Type* type);
            void set_statements(CompoundStatement* statements);
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

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);

        private:
            hdc::Token name;
            hdc::Class* klass;
            hdc::SourceFile* file;
            hdc::Type* return_type;
            std::vector<Parameter*> parameters;
            CompoundStatement* statements;
            SymbolTable* symbolTable;
    };
}

#endif
