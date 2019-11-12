#ifndef HDC_STATEMENT_H
#define HDC_STATEMENT_H

#include "ast/ASTNode.h"

namespace hdc {
    class Statement : public ASTNode {
        public:
            virtual ~Statement();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
