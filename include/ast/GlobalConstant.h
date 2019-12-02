#ifndef HDC_GLOBAL_CONSTANT_H
#define HDC_GLOBAL_CONSTANT_H

#include "ast/Expression.h"
#include "ast/Constant.h"

namespace hdc {
    class SourceFile;

    class GlobalConstant : public Constant {
        public:
            GlobalConstant();
            GlobalConstant(Token& token);
            GlobalConstant(Token& token, Type* type, Expression* expression);
            GlobalConstant(Token& token, Expression* expression);

        public:
            ~GlobalConstant();

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
