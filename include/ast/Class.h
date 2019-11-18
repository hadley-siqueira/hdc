#ifndef CLASS_H
#define CLASS_H

#include <vector>

#include "ASTNode.h"
#include "ast/SourceFile.h"
#include "ast/Def.h"
#include "ast/IdentifierExpression.h"

namespace hdc {
    class SourceFile;
    class Def;

    class Class : public ASTNode {
        /* Constructors */
        public:
            Class();

        /* Destructors */
        public:
            ~Class();

        /* Setters */
        public:
            void setName(Token& token);
            void setParent(IdentifierExpression* parent);

        /* Getters */
        public:
            std::string getName();
            IdentifierExpression* getParent();
            Def* getMethod(int i);

        /* Predicates */
        public:
            bool hasParent();
            int n_methods();

        public:
            void addMethod(Def* def);

        /* Visitors */
        public:
            void accept(Visitor* visitor);

        private:
            Token name;
            IdentifierExpression* parent;
            SourceFile* file;
            std::vector<Def*> methods;

    };
}

#endif
