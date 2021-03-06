#ifndef SOURCE_FILE_H
#define SOURCE_FILE_H

#include <string>
#include <vector>

#include "ast/ASTNode.h"
#include "ast/Import.h"
#include "ast/Def.h"
#include "ast/Class.h"
#include "ast/Struct.h"
#include "ast/GlobalVariable.h"

#include "visitors/Visitor.h"
#include "symtab/SymbolTable.h"

namespace hdc {
    class Class;
    class Struct;
    class Def;

    class SourceFile : public ASTNode {
        public:
            SourceFile();
            SourceFile(std::string& path);

            ~SourceFile();

            void addImport(Import* import);
            void addClass(Class* klass);
            void addStruct(Struct* s);
            void addDef(Def* def);
            void addGlobalVariable(GlobalVariable* var);
            void addGlobalConstant(GlobalConstant* var);

            int n_defs();
            int n_imports();
            int n_classes();
            int n_structures();
            int n_global_variables();
            int n_global_constants();

            Class* getClass(int i);
            Struct* getStruct(int i);
            Def* getDef(int i);
            Import* getImport(int i);
            Import* getImportWithAlias(std::string alias);
            GlobalVariable* getGlobalVariable(int i);
            GlobalConstant* getGlobalConstant(int i);

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
            std::vector<Struct*> structures;
            std::vector<Import*> imports;
            std::vector<Def*> defs;
            std::vector<GlobalVariable*> globalVariables;
            std::vector<GlobalConstant*> globalConstants;
            SymbolTable* symbolTable;
    };
}

#endif
