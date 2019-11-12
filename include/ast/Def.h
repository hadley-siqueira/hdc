#ifndef HDC_DEF_H
#define HDC_DEF_H

#include <vector>

#include "token/Token.h"

#include "ast/ASTNode.h"
#include "ast/Class.h"
#include "ast/Type.h"
#include "ast/Parameter.h"

#include "ast/Statement.h"
#include "ast/CompoundStatement.h"

namespace hdc {
    class Class;
    class SourceFile;

    class Def : public ASTNode {
        private:
            hdc::Token name;
            hdc::Class* klass;
            hdc::SourceFile* file;
            hdc::Type* return_type;
            std::vector<Parameter*> parameters;
            CompoundStatement* statements;

        public:
            Def();
            ~Def();

        public:
            void set_name(hdc::Token name);
            void set_class(hdc::Class* klass);
            void set_file(hdc::SourceFile* file);
            void set_return_type(Type* type);
            void set_statements(CompoundStatement* statements);

            std::string get_name();
            Parameter* get_parameter(int i);
            Type* get_return_type();
            CompoundStatement* get_statements();

            void add_parameter(hdc::Token& name, Type* type);
            int n_parameters();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
