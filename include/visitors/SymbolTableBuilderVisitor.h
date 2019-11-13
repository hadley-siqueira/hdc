#ifndef HDC_SYMBOLTABLE_BUILDER_VISITOR_H
#define HDC_SYMBOLTABLE_BUILDER_VISITOR_H

#include "visitors/Visitor.h"
#include "ast/AST.h"
#include "symtab/SymbolTable.h"

namespace hdc {
    class SymbolTableBuilderVisitor : public Visitor {
        /* Constructors */
        public:
            SymbolTableBuilderVisitor();

        public:
        /* Visitor interface */
        public:
            virtual void visit(SourceFile* file) override;
            virtual void visit(Import* import) override;
            virtual void visit(Class* klass) override;
            virtual void visit(Def* def) override;
            virtual void visit(Parameter* parameter) override;
            virtual void visit(Type* type) override;
            virtual void visit(IntType* type) override;
            virtual void visit(UIntType* type) override;
            virtual void visit(ShortType* type) override;
            virtual void visit(UShortType* type) override;
            virtual void visit(LongType* type) override;
            virtual void visit(ULongType* type) override;
            virtual void visit(CharType* type) override;
            virtual void visit(UCharType* type) override;
            virtual void visit(FloatType* type) override;
            virtual void visit(DoubleType* type) override;
            virtual void visit(VoidType* type) override;
            virtual void visit(BoolType* type) override;
            virtual void visit(SymbolType* type) override;
            virtual void visit(Int8Type* type) override;
            virtual void visit(Int16Type* type) override;
            virtual void visit(Int32Type* type) override;
            virtual void visit(Int64Type* type) override;
            virtual void visit(UInt8Type* type) override;
            virtual void visit(UInt16Type* type) override;
            virtual void visit(UInt32Type* type) override;
            virtual void visit(UInt64Type* type) override;
            virtual void visit(PointerType* type) override;
            virtual void visit(Statement* statement) override;
            virtual void visit(CompoundStatement* statement) override;
            virtual void visit(WhileStatement* statement) override;
            virtual void visit(Expression* expression) override;
            virtual void visit(LogicalNotExpression* expression) override;
            virtual void visit(BitwiseNotExpression* expression) override;
            virtual void visit(AddressOfExpression* expression) override;
            virtual void visit(UnaryMinusExpression* expression) override;
            virtual void visit(UnaryPlusExpression* expression) override;
            virtual void visit(DolarExpression* expression) override;
            virtual void visit(ParenthesisExpression* expression) override;
            virtual void visit(DereferenceExpression* expression) override;
            virtual void visit(PreIncrementExpression* expression) override;
            virtual void visit(PreDecrementExpression* expression) override;
            virtual void visit(SizeOfExpression* expression) override;
            virtual void visit(CallExpression* expression) override;
            virtual void visit(DotExpression* expression) override;
            virtual void visit(ArrowExpression* expression) override;
            virtual void visit(IndexExpression* expression) override;
            virtual void visit(ShiftLeftLogicalExpression* expression) override;
            virtual void visit(ShiftRightLogicalExpression* expression) override;
            virtual void visit(ShiftRightArithmeticExpression* expression) override;
            virtual void visit(BitwiseAndExpression* expression) override;
            virtual void visit(BitwiseXorExpression* expression) override;
            virtual void visit(BitwiseOrExpression* expression) override;
            virtual void visit(TimesExpression* expression) override;
            virtual void visit(DivisionExpression* expression) override;
            virtual void visit(IntegerDivisionExpression* expression) override;
            virtual void visit(ModuloExpression* expression) override;
            virtual void visit(PlusExpression* expression) override;
            virtual void visit(MinusExpression* expression) override;
            virtual void visit(LessThanExpression* expression) override;
            virtual void visit(GreaterThanExpression* expression) override;
            virtual void visit(LessThanOrEqualExpression* expression) override;
            virtual void visit(GreaterThanOrEqualExpression* expression) override;
            virtual void visit(AssignmentExpression* expression) override;
            virtual void visit(BitwiseAndAssignmentExpression* expression) override;
            virtual void visit(BitwiseXorAssignmentExpression* expression) override;
            virtual void visit(BitwiseOrAssignmentExpression* expression) override;
            virtual void visit(BitwiseNotAssignmentExpression* expression) override;
            virtual void visit(DivisionAssignmentExpression* expression) override;
            virtual void visit(IntegerDivisionAssignmentExpression* expression) override;
            virtual void visit(MinusAssignmentExpression* expression) override;
            virtual void visit(ModuloAssignmentExpression* expression) override;
            virtual void visit(PlusAssignmentExpression* expression) override;
            virtual void visit(TimesAssignmentExpression* expression) override;
            virtual void visit(SllAssignmentExpression* expression) override;
            virtual void visit(SraAssignmentExpression* expression) override;
            virtual void visit(SrlAssignmentExpression* expression) override;
            virtual void visit(SpecialAssignmentExpression* expression) override;
            virtual void visit(LiteralIntegerExpression* expression) override;
            virtual void visit(IdentifierExpression* id) override;

        private:
            // pointer to the current symboltable
            SymbolTable* symbolTable;
            Class* klass;
    };
}
#endif
