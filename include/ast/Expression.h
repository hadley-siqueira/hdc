#ifndef HDC_EXPRESSION_H
#define HDC_EXPRESSION_H

#include "ast/Statement.h"

namespace hdc {
    class Expression : public Statement {
        public:
            virtual ~Expression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
