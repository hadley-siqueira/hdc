#ifndef HDC_GLOBAL_VARIABLE_H
#define HDC_GLOBAL_VARIABLE_H


#include "ast/Expression.h"
#include "ast/Variable.h"

namespace hdc {
    class SourceFile;

    class GlobalVariable : public Variable {
        public:
            GlobalVariable();
            GlobalVariable(Token& token);
            GlobalVariable(Token& token, Type* type);
            GlobalVariable(Token& token, Type* type, Expression* expression);
            GlobalVariable(Token& token, Expression* expression);

        public:
            ~GlobalVariable();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);

            Expression* getExpression() const;
            void setExpression(Expression* value);

            SourceFile* getSourceFile() const;
            void setSourceFile(SourceFile* value);

        private:
            Expression* expression;
            SourceFile* sourceFile;
    };
}

#endif
