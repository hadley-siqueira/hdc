#ifndef HDC_STRUCT_FIELD_H
#define HDC_STRUCT_FIELD_H

#include "token/Token.h"
#include "ast/Variable.h"
#include "ast/types/Type.h"

namespace hdc {
    class StructField : public Variable {
        public:
            StructField();
            StructField(Token& token, Type* type);

            ~StructField();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);
    };
}

#endif
