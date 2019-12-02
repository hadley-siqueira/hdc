#ifndef CLASS_H
#define CLASS_H

#include <vector>

#include "ASTNode.h"
#include "ast/SourceFile.h"
#include "ast/IdentifierExpression.h"
#include "ast/ClassVariable.h"
#include "symtab/SymbolTable.h"

namespace hdc {
    class SourceFile;
    class SymbolTable;

    class Struct : public ASTNode {
        /* Constructors */
        public:
            Struct();

        /* Destructors */
        public:
            ~Struct();

        /* Setters */
        public:
            void setName(Token& token);
            void setParent(IdentifierExpression* parent);

        /* Getters */
        public:
            std::string getName();
            IdentifierExpression* getParent();
            Def* getMethod(int i);
            ClassVariable* getVariable(int i);
            int getLine();
            int getColumn();

        /* Predicates */
        public:
            bool hasParent();
            int n_methods();
            int n_variables();

        public:
            void addMethod(Def* def);
            void addVariable(ClassVariable* variable);

        /* Visitors */
        public:
            void accept(Visitor* visitor);

            SymbolTable* getSymbolTable() const;
            void setSymbolTable(SymbolTable* value);

        private:
            Token name;
            IdentifierExpression* parent;
            SourceFile* file;
            std::vector<Def*> methods;
            std::vector<ClassVariable*> variables;
            SymbolTable* symbolTable;

    };
}

#endif
