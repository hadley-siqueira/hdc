#ifndef HDC_PARAMETER_H
#define HDC_PARAMETER_H

#include "token/Token.h"
#include "ast/Variable.h"
#include "ast/Type.h"


namespace hdc {
    class Parameter : public Variable {
        public:
            Parameter();
            Parameter(Token& token, Type* type);

            ~Parameter();

            std::string getUniqueCppName();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
