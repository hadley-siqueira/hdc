#ifndef HDC_PRETTY_PRINTER_H
#define HDC_PRETTY_PRINTER_H

#include <sstream>

#include "visitors/Visitor.h"
//#include "ast/AST.h"

namespace hdc {
    class PrettyPrinter : public Visitor {
        private:
            int n_spaces;
            std::stringstream output;

        public:
            PrettyPrinter();

        private:
            void print_indentation();
            void indent();
            void dedent();

        public:
            void print();

        public:
            void visit(Program* program);
            void visit(SourceFile* file);
            void visit(Import* import);

            void visit(Class* klass);
            void visit(Struct* s);
            void visit(Def* def);

            /* Variables */
            void visit(Parameter* parameter);
            void visit(Variable* variable);
            void visit(LocalVariable* variable);
            void visit(GlobalVariable* variable);
            void visit(ClassVariable* variable);

            /* Constants */
            void visit(Constant* c);
            void visit(GlobalConstant* c);

            /* Types */
            void visit(Type* type);
            void visit(IntType* type);
            void visit(UIntType* type);
            void visit(ShortType* type);
            void visit(UShortType* type);
            void visit(LongType* type);
            void visit(ULongType* type);
            void visit(CharType* type);
            void visit(UCharType* type);
            void visit(FloatType* type);
            void visit(DoubleType* type);
            void visit(VoidType* type);
            void visit(BoolType* type);
            void visit(SymbolType* type);
            void visit(Int8Type* type);
            void visit(Int16Type* type);
            void visit(Int32Type* type);
            void visit(Int64Type* type);
            void visit(UInt8Type* type);
            void visit(UInt16Type* type);
            void visit(UInt32Type* type);
            void visit(UInt64Type* type);
            void visit(PointerType* type);
            void visit(NamedType* type);
            void visit(FunctionType* type);

            /* Statements */
            void visit(Statement* statement);
            void visit(CompoundStatement* statement);
            void visit(WhileStatement* statement);
            void visit(ForStatement* statement);
            void visit(ForEachStatement* statement);
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
            void visit(AtExpression* expression);
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

            void visit(LogicalAndExpression* expression);

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
            void visit(LiteralNullExpression* expression);
            void visit(ListExpression* list);
            void visit(ArrayExpression* array);

            void visit(IdentifierExpression* id);
    };
}

#endif
