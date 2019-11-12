#ifndef HDC_TYPE_H
#define HDC_TYPE_H

#include "ast/ASTNode.h"

namespace hdc {
    class Type : public ASTNode {
        public:
            virtual ~Type();

        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
