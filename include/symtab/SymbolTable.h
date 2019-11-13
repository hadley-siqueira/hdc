#ifndef HDC_SYMBOLTABLE_H
#define HDC_SYMBOLTABLE_H

#include <map>
#include "symtab/Symbol.h"

namespace hdc {
    class SourceFile;
    class Def;

    class SymbolTable {
        public:
            bool hasParent();

        /* Actions */
        public:
            void addDef(Def* def);
            void addLocalVar(std::string name);

        /* Predicates */
        public:
            Symbol* has(std::string& name);

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
