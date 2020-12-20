#ifndef HDC_EXPRESSION_H
#define HDC_EXPRESSION_H

#include "ast/types/Type.h"
#include "ast/Statement.h"

namespace hdc {
    class Expression : public Statement {
        /* Constructors */
        public:
            Expression();

        /* Destructors */
        public:
            virtual ~Expression();

        public:
            Type* getType() const;
            void setType(Type* value);

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);

        private:
            Type* type;
    };
}

#endif
