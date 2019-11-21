#ifndef HDC_CPP_PRINTER_H
#define HDC_CPP_PRINTER_H

#include <sstream>
#include <string>
#include "visitors/Visitor.h"
#include "ast/AST.h"

namespace hdc {
    class CppPrinter : public Visitor {
        public:
            CppPrinter();

        public:
            std::string print();
            void save(std::string path);

        /* Visitor */
        public:
            virtual void visit(SourceFile* file);
            virtual void visit(Import* import);

            virtual void visit(Class* klass);
            virtual void visit(Def* def);

            /* Variables */
            virtual void visit(Parameter* parameter);
            virtual void visit(Variable* variable);
            virtual void visit(LocalVariable* variable);

            /* Types */
            virtual void visit(Type* type);
            virtual void visit(IntType* type);
            virtual void visit(UIntType* type);
            virtual void visit(ShortType* type);
            virtual void visit(UShortType* type);
            virtual void visit(LongType* type);
            virtual void visit(ULongType* type);
            virtual void visit(CharType* type);
            virtual void visit(UCharType* type);
            virtual void visit(FloatType* type);
            virtual void visit(DoubleType* type);
            virtual void visit(VoidType* type);
            virtual void visit(BoolType* type);
            virtual void visit(SymbolType* type);
            virtual void visit(Int8Type* type);
            virtual void visit(Int16Type* type);
            virtual void visit(Int32Type* type);
            virtual void visit(Int64Type* type);
            virtual void visit(UInt8Type* type);
            virtual void visit(UInt16Type* type);
            virtual void visit(UInt32Type* type);
            virtual void visit(UInt64Type* type);
            virtual void visit(PointerType* type);

            /* Statements */
            virtual void visit(Statement* statement);
            virtual void visit(CompoundStatement* statement);
            virtual void visit(WhileStatement* statement);
            virtual void visit(IfStatement* statement);
            virtual void visit(ElifStatement* statement);
            virtual void visit(ElseStatement* statement);

            /* Expressions */
            virtual void visit(Expression* expression);

            /* Unary Expressions */
            virtual void visit(LogicalNotExpression* expression);
            virtual void visit(BitwiseNotExpression* expression);
            virtual void visit(AddressOfExpression* expression);
            virtual void visit(UnaryMinusExpression* expression);
            virtual void visit(UnaryPlusExpression* expression);
            virtual void visit(DolarExpression* expression);
            virtual void visit(ParenthesisExpression* expression);
            virtual void visit(DereferenceExpression* expression);
            virtual void visit(PreIncrementExpression* expression);
            virtual void visit(PreDecrementExpression* expression);
            virtual void visit(SizeOfExpression* expression);

            /* Binary Expresisons */
            virtual void visit(CallExpression* expression);
            virtual void visit(DotExpression* expression);
            virtual void visit(ArrowExpression* expression);
            virtual void visit(IndexExpression* expression);

            virtual void visit(ShiftLeftLogicalExpression* expression);
            virtual void visit(ShiftRightLogicalExpression* expression);
            virtual void visit(ShiftRightArithmeticExpression* expression);

            virtual void visit(BitwiseAndExpression* expression);
            virtual void visit(BitwiseXorExpression* expression);
            virtual void visit(BitwiseOrExpression* expression);

            virtual void visit(TimesExpression* expression);
            virtual void visit(DivisionExpression* expression);
            virtual void visit(IntegerDivisionExpression* expression);
            virtual void visit(ModuloExpression* expression);

            virtual void visit(PlusExpression* expression);
            virtual void visit(MinusExpression* expression);

            virtual void visit(LessThanExpression* expression);
            virtual void visit(GreaterThanExpression* expression);
            virtual void visit(LessThanOrEqualExpression* expression);
            virtual void visit(GreaterThanOrEqualExpression* expression);
            virtual void visit(EqualExpression* expression);
            virtual void visit(NotEqualExpression* expression);

            virtual void visit(AssignmentExpression* expression);
            virtual void visit(BitwiseAndAssignmentExpression* expression);
            virtual void visit(BitwiseXorAssignmentExpression* expression);
            virtual void visit(BitwiseOrAssignmentExpression* expression);
            virtual void visit(BitwiseNotAssignmentExpression* expression);
            virtual void visit(DivisionAssignmentExpression* expression);
            virtual void visit(IntegerDivisionAssignmentExpression* expression);
            virtual void visit(MinusAssignmentExpression* expression);
            virtual void visit(ModuloAssignmentExpression* expression);
            virtual void visit(PlusAssignmentExpression* expression);
            virtual void visit(TimesAssignmentExpression* expression);
            virtual void visit(SllAssignmentExpression* expression);
            virtual void visit(SraAssignmentExpression* expression);
            virtual void visit(SrlAssignmentExpression* expression);
            virtual void visit(SpecialAssignmentExpression* expression);

            virtual void visit(LiteralIntegerExpression* expression);

            virtual void visit(IdentifierExpression* id);

        private:
            void print_indentation();
            void indent();
            void dedent();

        private:
            void generateDefParameters(Def* def);
            void generateDefLocalVariables(Def* def);

        private:
            int n_spaces;
            std::stringstream output;
            bool isExpression;
            bool prototypeFlag;
    };
}

#endif
