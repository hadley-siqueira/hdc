#ifndef HDC_PRETTY_PRINTER_H
#define HDC_PRETTY_PRINTER_H

#include <sstream>
#include "visitors/Visitor.h"

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
            virtual void visit(class SourceFile* file);
            virtual void visit(class Import* import);

            virtual void visit(class Class* klass);
            virtual void visit(class Def* def);
            virtual void visit(class Parameter* parameter);

            /* Types */
            virtual void visit(class Type* type);
            virtual void visit(class IntType* type);
            virtual void visit(class UIntType* type);
            virtual void visit(class ShortType* type);
            virtual void visit(class UShortType* type);
            virtual void visit(class LongType* type);
            virtual void visit(class ULongType* type);
            virtual void visit(class CharType* type);
            virtual void visit(class UCharType* type);
            virtual void visit(class FloatType* type);
            virtual void visit(class DoubleType* type);
            virtual void visit(class VoidType* type);
            virtual void visit(class BoolType* type);
            virtual void visit(class SymbolType* type);
            virtual void visit(class Int8Type* type);
            virtual void visit(class Int16Type* type);
            virtual void visit(class Int32Type* type);
            virtual void visit(class Int64Type* type);
            virtual void visit(class UInt8Type* type);
            virtual void visit(class UInt16Type* type);
            virtual void visit(class UInt32Type* type);
            virtual void visit(class UInt64Type* type);
            virtual void visit(class PointerType* type);

            /* Statements */
            virtual void visit(class Statement* statement);
            virtual void visit(class CompoundStatement* statement);
            virtual void visit(class WhileStatement* statement);

            /* Expressions */
            virtual void visit(class Expression* expression);

            /* Unary Expressions */
            virtual void visit(class LogicalNotExpression* expression);
            virtual void visit(class BitwiseNotExpression* expression);
            virtual void visit(class AddressOfExpression* expression);
            virtual void visit(class UnaryMinusExpression* expression);
            virtual void visit(class UnaryPlusExpression* expression);
            virtual void visit(class DolarExpression* expression);
            virtual void visit(class ParenthesisExpression* expression);
            virtual void visit(class DereferenceExpression* expression);
            virtual void visit(class PreIncrementExpression* expression);
            virtual void visit(class PreDecrementExpression* expression);
            virtual void visit(class SizeOfExpression* expression);

            /* Binary Expresisons */
            virtual void visit(class CallExpression* expression);
            virtual void visit(class DotExpression* expression);
            virtual void visit(class ArrowExpression* expression);
            virtual void visit(class IndexExpression* expression);

            virtual void visit(class ShiftLeftLogicalExpression* expression);
            virtual void visit(class ShiftRightLogicalExpression* expression);
            virtual void visit(class ShiftRightArithmeticExpression* expression);

            virtual void visit(class BitwiseAndExpression* expression);
            virtual void visit(class BitwiseXorExpression* expression);
            virtual void visit(class BitwiseOrExpression* expression);

            virtual void visit(class TimesExpression* expression);
            virtual void visit(class DivisionExpression* expression);
            virtual void visit(class IntegerDivisionExpression* expression);
            virtual void visit(class ModuloExpression* expression);

            virtual void visit(class PlusExpression* expression);
            virtual void visit(class MinusExpression* expression);

            virtual void visit(class LessThanExpression* expression);
            virtual void visit(class GreaterThanExpression* expression);
            virtual void visit(class LessThanOrEqualExpression* expression);
            virtual void visit(class GreaterThanOrEqualExpression* expression);

            virtual void visit(class AssignmentExpression* expression);
            virtual void visit(class BitwiseAndAssignmentExpression* expression);
            virtual void visit(class BitwiseXorAssignmentExpression* expression);
            virtual void visit(class BitwiseOrAssignmentExpression* expression);
            virtual void visit(class BitwiseNotAssignmentExpression* expression);
            virtual void visit(class DivisionAssignmentExpression* expression);
            virtual void visit(class IntegerDivisionAssignmentExpression* expression);
            virtual void visit(class MinusAssignmentExpression* expression);
            virtual void visit(class ModuloAssignmentExpression* expression);
            virtual void visit(class PlusAssignmentExpression* expression);
            virtual void visit(class TimesAssignmentExpression* expression);
            virtual void visit(class SllAssignmentExpression* expression);
            virtual void visit(class SraAssignmentExpression* expression);
            virtual void visit(class SrlAssignmentExpression* expression);
            virtual void visit(class SpecialAssignmentExpression* expression);

            virtual void visit(class LiteralIntegerExpression* expression);

            virtual void visit(class IdentifierExpression* id);
    };
}

#endif
