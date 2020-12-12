#ifndef HDC_LOCALVARIABLE_H
#define HDC_LOCALVARIABLE_H

#include "ast/Variable.h"

namespace hdc {
    class LocalVariable : public Variable {
        public:
            LocalVariable();
            LocalVariable(Token& token);

            std::string getUniqueCppName();
        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
