#ifndef HDC_PROGRAM_H
#define HDC_PROGRAM_H

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
#include "ast/SourceFile.h"

namespace hdc {
    class Program : public ASTNode {
    public:
        Program();
        ~Program();

    public:
        void addSourceFile(SourceFile* sfile);
        bool hasSourceFile(std::string path);
        SourceFile* getSourceFile(std::string path);
        std::map<std::string, SourceFile*>::iterator begin();
        std::map<std::string, SourceFile*>::iterator end();

    public:
        void accept(Visitor* visitor);

    private:
        std::map<std::string, SourceFile*> sourceFiles;
        int functionCounter;
        int classCounter;
    };
}

#endif // PROGRAM_H
