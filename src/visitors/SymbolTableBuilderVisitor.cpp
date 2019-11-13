#include <iostream>
#include "visitors/SymbolTableBuilderVisitor.h"
#include "ast/AST.h"

using namespace hdc;

/* Constructors */
SymbolTableBuilderVisitor::SymbolTableBuilderVisitor() {
    symbolTable = nullptr;
    klass = nullptr;
}

void SymbolTableBuilderVisitor::visit(SourceFile* file) {
    std::cout << "Building SymbolTable for file '" << file->getPath() << "'\n";

    SymbolTable* oldSymbolTable = symbolTable;
    symbolTable = new SymbolTable();

    // add functions to the symbolTable
    for (int i = 0; i < file->n_defs(); ++i) {
        symbolTable->addDef(file->getDef(i));
    }

    // add classes
    // add global variables
    // add constants

    for (int i = 0; i < file->n_defs(); ++i) {
        file->getDef(i)->accept(this);
    }

    file->setSymbolTable(symbolTable);
    symbolTable = oldSymbolTable;
}

void SymbolTableBuilderVisitor::visit(Import* import) {

}

void SymbolTableBuilderVisitor::visit(Class* klass) {

}

void SymbolTableBuilderVisitor::visit(Def* def) {
    SymbolTable* oldSymbolTable = symbolTable;

    symbolTable = new SymbolTable();

    if (klass != nullptr) {

    } else {
        def->getStatements()->accept(this);
    }

    def->setSymbolTable(symbolTable);
    symbolTable = oldSymbolTable;
}

void SymbolTableBuilderVisitor::visit(Parameter* parameter) {}
void SymbolTableBuilderVisitor::visit(Type* type) {}
void SymbolTableBuilderVisitor::visit(IntType* type) {}
void SymbolTableBuilderVisitor::visit(UIntType* type) {}
void SymbolTableBuilderVisitor::visit(ShortType* type) {}
void SymbolTableBuilderVisitor::visit(UShortType* type) {}
void SymbolTableBuilderVisitor::visit(LongType* type) {}
void SymbolTableBuilderVisitor::visit(ULongType* type) {}
void SymbolTableBuilderVisitor::visit(CharType* type) {}
void SymbolTableBuilderVisitor::visit(UCharType* type) {}
void SymbolTableBuilderVisitor::visit(FloatType* type) {}
void SymbolTableBuilderVisitor::visit(DoubleType* type) {}
void SymbolTableBuilderVisitor::visit(VoidType* type) {}
void SymbolTableBuilderVisitor::visit(BoolType* type) {}
void SymbolTableBuilderVisitor::visit(SymbolType* type) {}
void SymbolTableBuilderVisitor::visit(Int8Type* type) {}
void SymbolTableBuilderVisitor::visit(Int16Type* type) {}
void SymbolTableBuilderVisitor::visit(Int32Type* type) {}
void SymbolTableBuilderVisitor::visit(Int64Type* type) {}
void SymbolTableBuilderVisitor::visit(UInt8Type* type) {}
void SymbolTableBuilderVisitor::visit(UInt16Type* type) {}
void SymbolTableBuilderVisitor::visit(UInt32Type* type) {}
void SymbolTableBuilderVisitor::visit(UInt64Type* type) {}
void SymbolTableBuilderVisitor::visit(PointerType* type) {}
void SymbolTableBuilderVisitor::visit(Statement* statement) {}
void SymbolTableBuilderVisitor::visit(CompoundStatement* statement) {}
void SymbolTableBuilderVisitor::visit(WhileStatement* statement) {}
void SymbolTableBuilderVisitor::visit(Expression* expression) {}
void SymbolTableBuilderVisitor::visit(LogicalNotExpression* expression) {}
void SymbolTableBuilderVisitor::visit(BitwiseNotExpression* expression) {}
void SymbolTableBuilderVisitor::visit(AddressOfExpression* expression) {}
void SymbolTableBuilderVisitor::visit(UnaryMinusExpression* expression) {}
void SymbolTableBuilderVisitor::visit(UnaryPlusExpression* expression) {}
void SymbolTableBuilderVisitor::visit(DolarExpression* expression) {}
void SymbolTableBuilderVisitor::visit(ParenthesisExpression* expression) {}
void SymbolTableBuilderVisitor::visit(DereferenceExpression* expression) {}
void SymbolTableBuilderVisitor::visit(PreIncrementExpression* expression) {}
void SymbolTableBuilderVisitor::visit(PreDecrementExpression* expression) {}
void SymbolTableBuilderVisitor::visit(SizeOfExpression* expression) {}
void SymbolTableBuilderVisitor::visit(CallExpression* expression) {}
void SymbolTableBuilderVisitor::visit(DotExpression* expression) {}
void SymbolTableBuilderVisitor::visit(ArrowExpression* expression) {}
void SymbolTableBuilderVisitor::visit(IndexExpression* expression) {}
void SymbolTableBuilderVisitor::visit(ShiftLeftLogicalExpression* expression) {}
void SymbolTableBuilderVisitor::visit(ShiftRightLogicalExpression* expression) {}
void SymbolTableBuilderVisitor::visit(ShiftRightArithmeticExpression* expression) {}
void SymbolTableBuilderVisitor::visit(BitwiseAndExpression* expression) {}
void SymbolTableBuilderVisitor::visit(BitwiseXorExpression* expression) {}
void SymbolTableBuilderVisitor::visit(BitwiseOrExpression* expression) {}
void SymbolTableBuilderVisitor::visit(TimesExpression* expression) {}
void SymbolTableBuilderVisitor::visit(DivisionExpression* expression) {}
void SymbolTableBuilderVisitor::visit(IntegerDivisionExpression* expression) {}
void SymbolTableBuilderVisitor::visit(ModuloExpression* expression) {}
void SymbolTableBuilderVisitor::visit(PlusExpression* expression) {}
void SymbolTableBuilderVisitor::visit(MinusExpression* expression) {}
void SymbolTableBuilderVisitor::visit(LessThanExpression* expression) {}
void SymbolTableBuilderVisitor::visit(GreaterThanExpression* expression) {}
void SymbolTableBuilderVisitor::visit(LessThanOrEqualExpression* expression) {}
void SymbolTableBuilderVisitor::visit(GreaterThanOrEqualExpression* expression) {}

void SymbolTableBuilderVisitor::visit(AssignmentExpression* expression) {
    Expression* left;

    expression->getRight()->accept(this);
    left = expression->getLeft();

    if (left->getKind() == AST_IDENTIFIER) {
        IdentifierExpression* id = (IdentifierExpression*) left;

        std::cout << "Adding variable " << id->getName();
    }
}

void SymbolTableBuilderVisitor::visit(BitwiseAndAssignmentExpression* expression) {}
void SymbolTableBuilderVisitor::visit(BitwiseXorAssignmentExpression* expression) {}
void SymbolTableBuilderVisitor::visit(BitwiseOrAssignmentExpression* expression) {}
void SymbolTableBuilderVisitor::visit(BitwiseNotAssignmentExpression* expression) {}
void SymbolTableBuilderVisitor::visit(DivisionAssignmentExpression* expression) {}
void SymbolTableBuilderVisitor::visit(IntegerDivisionAssignmentExpression* expression) {}
void SymbolTableBuilderVisitor::visit(MinusAssignmentExpression* expression) {}
void SymbolTableBuilderVisitor::visit(ModuloAssignmentExpression* expression) {}
void SymbolTableBuilderVisitor::visit(PlusAssignmentExpression* expression) {}
void SymbolTableBuilderVisitor::visit(TimesAssignmentExpression* expression) {}
void SymbolTableBuilderVisitor::visit(SllAssignmentExpression* expression) {}
void SymbolTableBuilderVisitor::visit(SraAssignmentExpression* expression) {}
void SymbolTableBuilderVisitor::visit(SrlAssignmentExpression* expression) {}
void SymbolTableBuilderVisitor::visit(SpecialAssignmentExpression* expression) {}
void SymbolTableBuilderVisitor::visit(LiteralIntegerExpression* expression) {}
void SymbolTableBuilderVisitor::visit(IdentifierExpression* id) {}
