#ifndef HDC_ASSIGNMENT_EXPRESSION_H
#define HDC_ASSIGNMENT_EXPRESSION_H

#include "BinaryOperator.h"

namespace hdc {
    class AssignmentExpression : public BinaryOperator {
        /* Constructors */
        public:
            AssignmentExpression();
            AssignmentExpression(Expression* left, Expression* right);
            AssignmentExpression(Token& oper, Expression* left, Expression* right);

        /* Destructors */
        virtual ~AssignmentExpression();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor);

            bool getConstructorFlag() const;
            void setConstructorFlag(bool value);

    private:
            bool constructorFlag;
    };
}

#endif
