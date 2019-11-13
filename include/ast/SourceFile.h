#ifndef SOURCE_FILE_H
#define SOURCE_FILE_H

#include <string>
#include <vector>

#include "ast/ASTNode.h"
#include "ast/Import.h"
#include "ast/Def.h"
#include "ast/Class.h"

#include "visitors/Visitor.h"
#include "symtab/SymbolTable.h"

namespace hdc {
    class Class;
    class Def;

    class SourceFile : public ASTNode {
        public:
            SourceFile();
            SourceFile(std::string& path);

            ~SourceFile();

            void addImport(Import* import);
            void addClass(Class* klass);
            void addDef(Def* def);

            int n_defs();
            int n_imports();
            int n_classes();

            Class* getClass(int i);
            Def* getDef(int i);
            Import* getImport(int i);

        /* Getters */
        public:
            std::string getPath();
            SymbolTable* getSymbolTable() const;

        /* Setters */
        public:
            void setSymbolTable(SymbolTable* value);

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);

        private:
            std::string path;
            std::vector<Class*> classes;
            std::vector<Import*> imports;
            std::vector<Def*> defs;
            SymbolTable* symbolTable;
    };
}

#endif
