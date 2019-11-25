#ifndef IDENTIFIER_EXPRESSION_H
#define IDENTIFIER_EXPRESSION_H

#include "Expression.h"
#include "token/Token.h"
#include "symtab/Symbol.h"

namespace hdc {
    class Symbol;

    class IdentifierExpression : public Expression {
        public:
            IdentifierExpression();
            IdentifierExpression(Token& name);
            IdentifierExpression(Token& alias, Token& name);
            IdentifierExpression(IdentifierExpression* id);

        /* Destructors */
        public:
            virtual ~IdentifierExpression();

        /* Predicates */
        public:
            bool hasAlias();

        /* Getters */
        public:
            std::string getAlias();
            std::string getName();
            Token& getNameAsToken();
            Symbol* getSymbol() const;
            void setSymbol(Symbol* value);

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);

        private:
            Token name;
            Token alias;
            bool alias_flag;
            Symbol* symbol;
    };
}

#endif
