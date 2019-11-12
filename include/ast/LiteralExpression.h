#ifndef HDC_LITERAL_H
#define HDC_LITERAL_H

#include "token/Token.h"
#include "Expression.h"

namespace hdc {
    class LiteralExpression : public Expression {
        protected:
            Token token;

        /* Constructors */
        public:
            LiteralExpression();
            LiteralExpression(Token token);

        /* Destructors */
        public:
            virtual ~LiteralExpression();

        /* Setters */
        public:
            void set_token(Token token);

        /* Getters */
        public:
            Token get_token();

        /* Visitors */
        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
