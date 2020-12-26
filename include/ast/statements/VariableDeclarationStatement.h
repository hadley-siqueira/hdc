#ifndef HDC_VARIABLEDECLARATIONSTATEMENT_H
#define HDC_VARIABLEDECLARATIONSTATEMENT_H

#include "ast/Statement.h"
#include "ast/Expression.h"
#include "token/Token.h"
#include "ast/IdentifierExpression.h"

namespace hdc {
    class VariableDeclarationStatement : public Statement {
    public:
        VariableDeclarationStatement(IdentifierExpression* name, Type* type, Expression* expression);
        virtual ~VariableDeclarationStatement();

    public:
        void accept(Visitor* visitor);

        IdentifierExpression* getName() const;
        void setName(IdentifierExpression *value);

        Type *getType() const;
        void setType(Type *value);

        Expression *getExpression() const;
        void setExpression(Expression *value);

    private:
        IdentifierExpression* name;
        Type* type;
        Expression* expression;
    };
}

#endif // VARIABLEDECLARATIONSTATEMENT_H
