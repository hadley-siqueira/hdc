#ifndef CLASS_H
#define CLASS_H

#include <vector>

#include "ASTNode.h"
#include "ast/SourceFile.h"
#include "ast/Def.h"
#include "ast/IdentifierExpression.h"
#include "ast/ClassVariable.h"
#include "symtab/SymbolTable.h"

namespace hdc {
    class SourceFile;
    class Def;
    class SymbolTable;

    class Class : public ASTNode {
        /* Constructors */
        public:
            Class();

        /* Destructors */
        public:
            ~Class();

        /* Setters */
        public:
            void setName(Token& token);
            void setSuperClass(IdentifierExpression* superClass);

        /* Getters */
        public:
            std::string getName();
            std::string getUniqueCppName();
            IdentifierExpression* getParentNode();
            Def* getMethod(int i);
            Def* getConstructor(int i);
            Def* getDestructor();
            ClassVariable* getVariable(int i);
            int getLine();
            int getColumn();

            ClassVariable* getVariable(std::string name);

        /* Setters */
        public:
            void setSourceFile(SourceFile* s);

        /* Predicates */
        public:
            bool hasSuperClass();
            int n_methods();
            int n_variables();
            int n_constructors();

        public:
            void addMethod(Def* def);
            void addVariable(ClassVariable* variable);

        /* Visitors */
        public:
            void accept(Visitor* visitor);

            SymbolTable* getSymbolTable() const;
            void setSymbolTable(SymbolTable* value);

            int getId() const;
            void setId(int value);

            int getGlobalId() const;
            void setGlobalId(int value);

            Type *getSelfType();

    private:
            int classVariableCounter;
            int methodCounter;
            int id;
            int globalId;

            Token name;

            IdentifierExpression* superClass;
            SourceFile* file;
            Def* destructor;
            SymbolTable* symbolTable;
            NamedType* selfType;

            std::vector<ClassVariable*> variables;
            std::vector<Def*> methods;
            std::vector<Def*> constructors;

    };
}

#endif
