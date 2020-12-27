#ifndef HDC_VISITOR_H
#define HDC_VISITOR_H

#include <string>

namespace hdc {
    /* This is one of the base classes to visit ASTNodes */
    class Visitor {
        public:
            virtual void visit(class Program* program)=0;
            virtual void visit(class SourceFile* file)=0;
            virtual void visit(class Import* import)=0;

            virtual void visit(class Class* klass)=0;
            virtual void visit(class Struct* s)=0;
            virtual void visit(class Def* def)=0;

            /* Variables */
            virtual void visit(class Variable* variable)=0;
            virtual void visit(class Parameter* parameter)=0;
            virtual void visit(class LocalVariable* variable)=0;
            virtual void visit(class GlobalVariable* variable)=0;
            virtual void visit(class ClassVariable* variable)=0;

            /* Constants */
            virtual void visit(class Constant* c)=0;
            virtual void visit(class GlobalConstant* c)=0;

            /* Types */
            virtual void visit(class Type* type)=0;
            virtual void visit(class IntType* type)=0;
            virtual void visit(class UIntType* type)=0;
            virtual void visit(class ShortType* type)=0;
            virtual void visit(class UShortType* type)=0;
            virtual void visit(class LongType* type)=0;
            virtual void visit(class ULongType* type)=0;
            virtual void visit(class CharType* type)=0;
            virtual void visit(class UCharType* type)=0;
            virtual void visit(class FloatType* type)=0;
            virtual void visit(class DoubleType* type)=0;
            virtual void visit(class VoidType* type)=0;
            virtual void visit(class BoolType* type)=0;
            virtual void visit(class SymbolType* type)=0;
            virtual void visit(class Int8Type* type)=0;
            virtual void visit(class Int16Type* type)=0;
            virtual void visit(class Int32Type* type)=0;
            virtual void visit(class Int64Type* type)=0;
            virtual void visit(class UInt8Type* type)=0;
            virtual void visit(class UInt16Type* type)=0;
            virtual void visit(class UInt32Type* type)=0;
            virtual void visit(class UInt64Type* type)=0;
            virtual void visit(class PointerType* type)=0;
            virtual void visit(class NamedType* type)=0;
            virtual void visit(class FunctionType* type)=0;
            virtual void visit(class ArrayType* type)=0;

            /* Statements */
            virtual void visit(class Statement* statement)=0;
            virtual void visit(class CompoundStatement* statement)=0;
            virtual void visit(class WhileStatement* statement)=0;
            virtual void visit(class ForStatement* statement)=0;
            virtual void visit(class ForEachStatement* statement)=0;
            virtual void visit(class IfStatement* statement)=0;
            virtual void visit(class ElifStatement* statement)=0;
            virtual void visit(class ElseStatement* statement)=0;
            virtual void visit(class ReturnStatement* statement)=0;
            virtual void visit(class VariableDeclarationStatement* statement)=0;

            /* Expressions */
            virtual void visit(class Expression* expression)=0;

            /* Unary Expressions */
            virtual void visit(class LogicalNotExpression* expression)=0;
            virtual void visit(class BitwiseNotExpression* expression)=0;
            virtual void visit(class AddressOfExpression* expression)=0;
            virtual void visit(class UnaryMinusExpression* expression)=0;
            virtual void visit(class UnaryPlusExpression* expression)=0;
            virtual void visit(class DolarExpression* expression)=0;
            virtual void visit(class AtExpression* expression)=0;
            virtual void visit(class ParenthesisExpression* expression)=0;
            virtual void visit(class DereferenceExpression* expression)=0;
            virtual void visit(class PreIncrementExpression* expression)=0;
            virtual void visit(class PreDecrementExpression* expression)=0;
            virtual void visit(class SizeOfExpression* expression)=0;
        
            /* Binary Expressions */
            virtual void visit(class CallExpression* expression)=0;
            virtual void visit(class DotExpression* expression)=0;
            virtual void visit(class ArrowExpression* expression)=0;
            virtual void visit(class IndexExpression* expression)=0;

            virtual void visit(class ShiftLeftLogicalExpression* expression)=0;
            virtual void visit(class ShiftRightLogicalExpression* expression)=0;
            virtual void visit(class ShiftRightArithmeticExpression* expression)=0;

            virtual void visit(class BitwiseAndExpression* expression)=0;
            virtual void visit(class BitwiseXorExpression* expression)=0;
            virtual void visit(class BitwiseOrExpression* expression)=0;

            virtual void visit(class TimesExpression* expression)=0;
            virtual void visit(class DivisionExpression* expression)=0;
            virtual void visit(class IntegerDivisionExpression* expression)=0;
            virtual void visit(class ModuloExpression* expression)=0;

            virtual void visit(class PlusExpression* expression)=0;
            virtual void visit(class MinusExpression* expression)=0;

            virtual void visit(class LessThanExpression* expression)=0;
            virtual void visit(class GreaterThanExpression* expression)=0;
            virtual void visit(class LessThanOrEqualExpression* expression)=0;
            virtual void visit(class GreaterThanOrEqualExpression* expression)=0;
            virtual void visit(class EqualExpression* expression)=0;
            virtual void visit(class NotEqualExpression* expression)=0;

            virtual void visit(class LogicalAndExpression* expression)=0;
            virtual void visit(class LogicalOrExpression* expression)=0;

            virtual void visit(class AssignmentExpression* expression)=0;
            virtual void visit(class BitwiseAndAssignmentExpression* expression)=0;
            virtual void visit(class BitwiseXorAssignmentExpression* expression)=0;
            virtual void visit(class BitwiseOrAssignmentExpression* expression)=0;
            virtual void visit(class BitwiseNotAssignmentExpression* expression)=0;
            virtual void visit(class DivisionAssignmentExpression* expression)=0;
            virtual void visit(class IntegerDivisionAssignmentExpression* expression)=0;
            virtual void visit(class MinusAssignmentExpression* expression)=0;
            virtual void visit(class ModuloAssignmentExpression* expression)=0;
            virtual void visit(class PlusAssignmentExpression* expression)=0;
            virtual void visit(class TimesAssignmentExpression* expression)=0;
            virtual void visit(class SllAssignmentExpression* expression)=0;
            virtual void visit(class SraAssignmentExpression* expression)=0;
            virtual void visit(class SrlAssignmentExpression* expression)=0;
            virtual void visit(class SpecialAssignmentExpression* expression)=0;

            /* Literals */
            virtual void visit(class LiteralIntegerExpression* expression)=0;
            virtual void visit(class LiteralStringExpression* expression)=0;
            virtual void visit(class LiteralCharExpression* expression)=0;
            virtual void visit(class LiteralFloatExpression* expression)=0;
            virtual void visit(class LiteralDoubleExpression* expression)=0;
            virtual void visit(class LiteralSymbolExpression* expression)=0;
            virtual void visit(class LiteralBoolExpression* expression)=0;
            virtual void visit(class LiteralNullExpression* expression)=0;
            virtual void visit(class ListExpression* list)=0;
            virtual void visit(class ArrayExpression* array)=0;

            virtual void visit(class IdentifierExpression* id)=0;
    };
}

#endif
