#ifndef HDC_TYPE_CHECKER_VISITOR_H
#define HDC_TYPE_CHECKER_VISITOR_H

#include "visitors/Visitor.h"
#include "ast/AST.h"
#include "symtab/SymbolTable.h"
#include "symtab/SymbolTableStack.h"

namespace hdc {
    class TypeCheckerVisitor : public Visitor {
        /* Constructors */
        public:
            TypeCheckerVisitor();

        /* Destructors */
        public:
            ~TypeCheckerVisitor();

        /* Visitor interface */
        public:
            void visit(SourceFile* file);
            void visit(Import* import);

            void visit(Class* klass);
            void visit(Def* def);

            /* Variables */
            void visit(Parameter* parameter);
            void visit(Variable* variable);
            void visit(LocalVariable* variable);

            /* Types */
            void visit(Type* lastType);
            void visit(IntType* lastType);
            void visit(UIntType* lastType);
            void visit(ShortType* lastType);
            void visit(UShortType* lastType);
            void visit(LongType* lastType);
            void visit(ULongType* lastType);
            void visit(CharType* lastType);
            void visit(UCharType* lastType);
            void visit(FloatType* lastType);
            void visit(DoubleType* lastType);
            void visit(VoidType* lastType);
            void visit(BoolType* lastType);
            void visit(SymbolType* lastType);
            void visit(Int8Type* lastType);
            void visit(Int16Type* lastType);
            void visit(Int32Type* lastType);
            void visit(Int64Type* lastType);
            void visit(UInt8Type* lastType);
            void visit(UInt16Type* lastType);
            void visit(UInt32Type* lastType);
            void visit(UInt64Type* lastType);
            void visit(PointerType* lastType);

            /* Statements */
            void visit(Statement* statement);
            void visit(CompoundStatement* statement);
            void visit(WhileStatement* statement);
            void visit(IfStatement* statement);
            void visit(ElifStatement* statement);
            void visit(ElseStatement* statement);
            void visit(ReturnStatement* statement);

            /* Expressions */
            void visit(Expression* expression);

            /* Unary Expressions */
            void visit(LogicalNotExpression* expression);
            void visit(BitwiseNotExpression* expression);
            void visit(AddressOfExpression* expression);
            void visit(UnaryMinusExpression* expression);
            void visit(UnaryPlusExpression* expression);
            void visit(DolarExpression* expression);
            void visit(ParenthesisExpression* expression);
            void visit(DereferenceExpression* expression);
            void visit(PreIncrementExpression* expression);
            void visit(PreDecrementExpression* expression);
            void visit(SizeOfExpression* expression);

            /* Binary Expresisons */
            void visit(CallExpression* expression);
            void visit(DotExpression* expression);
            void visit(ArrowExpression* expression);
            void visit(IndexExpression* expression);

            void visit(ShiftLeftLogicalExpression* expression);
            void visit(ShiftRightLogicalExpression* expression);
            void visit(ShiftRightArithmeticExpression* expression);

            void visit(BitwiseAndExpression* expression);
            void visit(BitwiseXorExpression* expression);
            void visit(BitwiseOrExpression* expression);

            void visit(TimesExpression* expression);
            void visit(DivisionExpression* expression);
            void visit(IntegerDivisionExpression* expression);
            void visit(ModuloExpression* expression);

            void visit(PlusExpression* expression);
            void visit(MinusExpression* expression);

            void visit(LessThanExpression* expression);
            void visit(GreaterThanExpression* expression);
            void visit(LessThanOrEqualExpression* expression);
            void visit(GreaterThanOrEqualExpression* expression);
            void visit(EqualExpression* expression);
            void visit(NotEqualExpression* expression);

            void visit(AssignmentExpression* expression);
            void visit(BitwiseAndAssignmentExpression* expression);
            void visit(BitwiseXorAssignmentExpression* expression);
            void visit(BitwiseOrAssignmentExpression* expression);
            void visit(BitwiseNotAssignmentExpression* expression);
            void visit(DivisionAssignmentExpression* expression);
            void visit(IntegerDivisionAssignmentExpression* expression);
            void visit(MinusAssignmentExpression* expression);
            void visit(ModuloAssignmentExpression* expression);
            void visit(PlusAssignmentExpression* expression);
            void visit(TimesAssignmentExpression* expression);
            void visit(SllAssignmentExpression* expression);
            void visit(SraAssignmentExpression* expression);
            void visit(SrlAssignmentExpression* expression);
            void visit(SpecialAssignmentExpression* expression);

            /* Literals */
            void visit(LiteralIntegerExpression* expression);
            void visit(LiteralStringExpression* expression);
            void visit(LiteralCharExpression* expression);
            void visit(LiteralFloatExpression* expression);
            void visit(LiteralDoubleExpression* expression);
            void visit(LiteralSymbolExpression* expression);
            void visit(LiteralBoolExpression* expression);

            void visit(IdentifierExpression* id);

        private:
            void checkFunctions(SourceFile* file);
            Type* typeCoercion(Type* left, Type* right);

        private:
            SymbolTableStack* symbolTableStack;
            SymbolTable* symbolTable;
            Type* lastType;
    };
}

#endif
