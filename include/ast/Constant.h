#ifndef HDC_CONSTANT_H
#define HDC_CONSTANT_H

#include "token/Token.h"
#include "ast/ASTNode.h"
#include "ast/Type.h"

namespace hdc {
    class Expression;

    class Constant : public ASTNode {
        /* Visitors */
        public:
            virtual void accept(Visitor* visitor)=0;

            Type* getType() const;
            void setType(Type* value);

            int getOffset() const;
            void setOffset(int value);

            std::string getName();

            int getLocalName() const;
            void setLocalName(int value);

            unsigned long long getGlobalName() const;
            void setGlobalName(unsigned long long value);

            bool getIsConstant() const;
            void setIsConstant(bool value);

            int getLine();
            int getColumn();

            Expression* getExpression() const;
            void setExpression(Expression* value);

        protected:
            Token token;
            Type* type;
            int offset;
            int localName;
            bool isConstant;
            unsigned long long globalName;
            Expression* expression;
    };
}

#endif
