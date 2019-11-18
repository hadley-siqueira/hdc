#ifndef PARAMETER_H
#define PARAMETER_H

#include "token/Token.h"
#include "ast/Variable.h"
#include "ast/Type.h"


namespace hdc {
    class Parameter : public Variable {
        public:
            Parameter();
            Parameter(Token& token, Type* type);

            ~Parameter();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
