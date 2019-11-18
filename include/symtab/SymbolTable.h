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
        public:
            bool hasParent();

        /* Actions */
        public:
            void addClass(Class* klass);
            void addDef(Def* def);
            void addLocalVariable(LocalVariable* var);
            void addParameter(Parameter* parameter);

        /* Predicates */
        public:
            Symbol* has(std::string& name);
            Symbol* hasLocalVariable(std::string& name);
            Symbol* hasLocalVariableOrParameter(const std::string& name);

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
