#ifndef HDC_CLASS_VARIABLE_H
#define HDC_CLASS_VARIABLE_H

#include "ast/Variable.h"

namespace hdc {
    class ClassVariable : public Variable {
        public:
            ClassVariable();
            ClassVariable(Token& token);
            ClassVariable(Token& token, Type* type);

            std::string getUniqueCppName();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
