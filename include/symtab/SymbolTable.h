#ifndef HDC_SYMBOLTABLE_H
#define HDC_SYMBOLTABLE_H

#include <map>
#include "symtab/Symbol.h"
#include "ast/LocalVariable.h"

namespace hdc {
    class SourceFile;
    class Def;
    class Symbol;

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

        /* Actions */
        public:
            Symbol* addClass(Class* klass);
            Symbol* addDef(Def* def);
            Symbol* addLocalVariable(LocalVariable* var);
            Symbol* addParameter(Parameter* parameter);
            Symbol* addMethod(Def* def);
            Symbol* addClassVariable(ClassVariable* var);

        /* Predicates */
        public:
            Symbol* has(std::string name);
            Symbol* hasLocalVariable(std::string& name);
            Symbol* hasLocalVariableOrParameter(const std::string& name);
            Symbol* hasClassVariable(std::string& name);

        /* Getters */
        public:
            SymbolTable* getParent() const;
            SourceFile* getSourceFile() const;

        /* Setters */
        public:
            void setParent(SymbolTable* parent);
            void setSourceFile(SourceFile* value);

        private:
            SymbolTable* parent;

            // pointer to search definitions on SourceFile
            SourceFile* sourceFile;

            std::map<std::string, Symbol*> symbols;

    };
}

#endif // SYMBOLTABLE_H
