#ifndef HDC_CLASSVARIABLE_H
#define HDC_CLASSVARIABLE_H

#include "ast/Variable.h"

namespace hdc {
    class ClassVariable : public Variable {
        public:
            ClassVariable();
            ClassVariable(Token& token);
            ClassVariable(Token& token, Type* type);

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
