#ifndef IMPORT_H
#define IMPORT_H

#include <string>
#include <vector>

#include "ast/ASTNode.h"
#include "token/Token.h"
#include "visitors/Visitor.h"

namespace hdc {
    class SourceFile;

    class Import : public ASTNode {
        public:
            bool hasAlias();
            void add(hdc::Token& token);
            void set_alias(hdc::Token& token);
            std::string str();
            bool isMultipleImport();

        public:
            virtual void accept(Visitor* visitor);

            SourceFile* getSourceFile() const;
            void setSourceFile(SourceFile* value);

            std::vector<hdc::Token> getPath() const;
            void setPath(const std::vector<hdc::Token>& value);

            void addSourceFile(SourceFile* file);

        private:
            std::vector<hdc::Token> path;
            hdc::Token alias;
            SourceFile* sourceFile;
            std::vector<SourceFile*> sourceFiles; // for multiple import
    };
}

#endif
