#ifndef HDC_VARIABLE_H
#define HDC_VARIABLE_H

#include "token/Token.h"
#include "ast/ASTNode.h"
#include "ast/Type.h"

namespace hdc {
    class Variable : public ASTNode {
        /* Visitors */
        public:
            virtual void accept(Visitor* visitor)=0;

            Type* getType() const;
            void setType(Type* value);

            int getOffset() const;
            void setOffset(int value);

            std::string getName();

        protected:
            Token token;
            Type* type;
            int offset;
    };
}

#endif
