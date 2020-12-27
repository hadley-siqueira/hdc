#ifndef HDC_ARRAYTYPE_H
#define HDC_ARRAYTYPE_H

#include "token/Token.h"
#include "ast/types/Type.h"
#include "ast/Expression.h"

namespace hdc {
    class ArrayType : public Type {
    public:
        ArrayType(Type* subtype, Token& token);
        ArrayType(Type* subtype, Expression* expression, Token& token);

        ~ArrayType();

    public:
        Type* clone();
        bool equals(Type* other);
        int getRank();

    public:
        void accept(Visitor* visitor);

        Type *getSubtype() const;
        void setSubtype(Type *value);

        Expression *getExpression() const;
        void setExpression(Expression *value);

    private:
        Type* subtype;
        Expression* expression;
        Token token;
    };
}

#endif // ARRAYTYPE_H
