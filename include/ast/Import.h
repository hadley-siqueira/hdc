#ifndef IMPORT_H
#define IMPORT_H

#include <string>
#include <vector>

#include "ast/ASTNode.h"
#include "token/Token.h"
#include "visitors/Visitor.h"

namespace hdc {
    class Import : public ASTNode {
        public:
            bool hasAlias();
            void add(hdc::Token& token);
            void set_alias(hdc::Token& token);
            std::string str();

        public:
            virtual void accept(Visitor* visitor);

        private:
            std::vector<hdc::Token> path;
            hdc::Token alias;
    };
}

#endif
