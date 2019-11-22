#ifndef HDC_RETURN_STATEMENT_H
#define HDC_RETURN_STATEMENT_H

#include "token/Token.h"
#include "ast/Statement.h"
#include "ast/Expression.h"

namespace hdc {
    class ReturnStatement : public Statement {
        /* Constructors */
        public:
            ReturnStatement();
            ReturnStatement(Token &token);
            ReturnStatement(Token& token, Expression* expression);

        /* Destructors */
        public:
            ~ReturnStatement();

        public:
            Expression* getExpression() const;
            void setExpression(Expression* value);

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);

        private:
            Token token;
            Expression* expression;
    };
}

#endif
