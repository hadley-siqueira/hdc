#ifndef HDC_SYMBOLTABLE_H
#define HDC_SYMBOLTABLE_H

#include <map>
#include "symtab/Symbol.h"
#include "ast/LocalVariable.h"

namespace hdc {
    class SourceFile;
    class Def;
    class Symbol;
    class Parameter;
    class ClassVariable;

    class SymbolTable {
        /* Constructors */
        public:
            SymbolTable();
            SymbolTable(SymbolTable* parent);

        /* Destructors */
        public:
            ~SymbolTable();

        public:
            bool hasParent();
            bool hasSuper();
            void dump();

        /* Actions */
        public:
            Symbol* add(Class* klass);
            Symbol* add(Def* def);
            Symbol* add(LocalVariable* var);
            Symbol* add(Parameter* parameter);
            Symbol* add(ClassVariable* var);
            Symbol* add(GlobalVariable* var);
            void addLiveVariable(Variable* var);

        /* Predicates */
        public:
            Symbol* has(std::string name);
            Symbol* hasLocal(std::string name);
            Symbol* hasLocalVariable(std::string& name);
            Symbol* hasLocalVariableOrParameter(const std::string& name);
            Symbol* hasLocalFunction(Def* def);
            Symbol* hasMethod(Def* def);
            Symbol* hasClassVariable(std::string& name);
            Symbol* hasLocalVariableOnCurrentScope(const std::string &name);

            int n_liveVariables();

        /* Getters */
        public:
            SymbolTable* getParent() const;
            SourceFile* getSourceFile() const;

            std::vector<Variable*> getLocalLiveVariables();
            std::vector<Variable*> getDefVariables();


        /* Setters */
        public:
            void setParent(SymbolTable* parent);
            void setSourceFile(SourceFile* value);

            SymbolTable *getSuperTable() const;
            void setSuperTable(SymbolTable *value);

    private:
            SymbolTable* parent;
            SymbolTable* superTable; // a pointer to parent class symtab

            // pointer to search definitions on SourceFile
            SourceFile* sourceFile;
            std::map<std::string, Symbol*> symbols;
    };
}

#endif // SYMBOLTABLE_H
