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
            void setSuperClass(NamedType* superClass);
            void setSymbolTable(SymbolTable* value);
            void setId(int value);
            void setGlobalId(int value);

        /* Getters */
        public:
            std::string getName();
            std::string getUniqueCppName();
            Def* getMethod(int i);
            Def* getConstructor(int i);
            Def* getDestructor();
            ClassVariable* getVariable(int i);
            int getLine();
            int getColumn();
            Type *getSelfType();
            int getGlobalId() const;
            int getId() const;
            SymbolTable* getSymbolTable() const;
            NamedType *getSuperClass() const;

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

    private:
            int classVariableCounter;
            int methodCounter;
            int id;
            int globalId;

            Token name;

            NamedType* superClass;
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
