#ifndef IDENTIFIER_EXPRESSION_H
#define IDENTIFIER_EXPRESSION_H

#include "Expression.h"
#include "token/Token.h"

namespace hdc {
    class IdentifierExpression : public Expression {
        private:
            Token name;
            Token alias;
            bool alias_flag;

        public:
            IdentifierExpression();
            IdentifierExpression(Token& name);
            IdentifierExpression(Token& alias, Token& name);

            virtual ~IdentifierExpression();

        /* Predicates */
        public:
            bool has_alias();

        /* Getters */
        public:
            std::string get_alias();
            std::string get_name();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
