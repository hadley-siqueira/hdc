#ifndef PARAMETER_H
#define PARAMETER_H

#include "token/Token.h"
#include "ast/ASTNode.h"
#include "ast/Type.h"


namespace hdc {
    class Parameter : public ASTNode {
        private:
            Token name;
            Type* type;

        public:
            Parameter();
            Parameter(Token& name, Type* type);

            ~Parameter();

        public:
            void set_name(Token& name);
            void set_type(Type* type);

            std::string get_name();
            Type* get_type();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
