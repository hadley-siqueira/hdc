#ifndef SOURCE_FILE_H
#define SOURCE_FILE_H

#include <string>
#include <vector>

#include "ast/ASTNode.h"
#include "ast/Import.h"
#include "ast/Def.h"
#include "ast/Class.h"

#include "visitors/Visitor.h"

namespace hdc {
    class Class;
    class Def;

    class SourceFile : public ASTNode {
        private:
            std::string path;
            std::vector<Class*> classes;
            std::vector<Import*> imports;
            std::vector<Def*> defs;

        public:
            SourceFile();
            SourceFile(std::string& path);

            ~SourceFile();

            void add_import(Import* import);
            void add_class(Class* klass);
            void add_def(Def* def);

            int n_defs();
            int n_imports();
            int n_classes();

            std::string get_path();
            
            Class* get_class(int i);
            Def* get_def(int i);
            Import* get_import(int i);

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
