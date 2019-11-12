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
            void set_name(Token& token);
            void set_parent(IdentifierExpression* parent);

        /* Getters */
        public:
            std::string get_name();
            IdentifierExpression* get_parent();
            Def* get_method(int i);

        /* Predicates */
        public:
            bool has_parent();
            int n_methods();

        public:
            void add_method(Def* def);

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
