#ifndef HDC_OPERH_TYPE_H
#define HDC_OPERH_TYPE_H

#include "PrimitiveType.h"
#include "../../token/Token.h"

namespace hdc {
    class OPERType : public PrimitiveType {
        private:
            Token token;

        public:
            OPERType();
            OPERType(Token& token);

        public:
            virtual void accept(Visitor& visitor);
    };
}

#endif
