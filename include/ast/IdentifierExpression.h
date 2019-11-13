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
            bool hasAlias();

        /* Getters */
        public:
            std::string getAlias();
            std::string getName();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
