#include <iostream>
#include "visitors/SymbolTableBuilderVisitor.h"
#include "ast/AST.h"

using namespace hdc;

/* Constructors */
SymbolTableBuilderVisitor::SymbolTableBuilderVisitor() {
    symbolTable = nullptr;
    currentClass = nullptr;
    checkingAssignment = false;
}

void SymbolTableBuilderVisitor::visit(SourceFile* file) {
    std::cout << "Building SymbolTable for file '" << file->getPath() << "'\n";

    SymbolTable* oldSymbolTable = symbolTable;
    symbolTable = new SymbolTable();
    file->setSymbolTable(symbolTable);

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

    symbolTable = oldSymbolTable;
}

void SymbolTableBuilderVisitor::visit(Import* import) {

}

void SymbolTableBuilderVisitor::visit(Class* klass) {

}

void SymbolTableBuilderVisitor::visit(Def* def) {
    SymbolTable* oldSymbolTable = symbolTable;

    symbolTable = new SymbolTable();
    symbolTable->setParent(oldSymbolTable);
    currentDef = def;

    def->setSymbolTable(symbolTable);

    for (int i = 0; i < def->n_parameters(); ++i) {
        symbolTable->addParameter(def->getParameter(i));
    }

    def->getStatements()->accept(this);

    symbolTable = oldSymbolTable;
}

void SymbolTableBuilderVisitor::visit(Parameter* parameter) {}

void SymbolTableBuilderVisitor::visit(Variable* variable) {

}

void SymbolTableBuilderVisitor::visit(LocalVariable* variable) {

}

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

void SymbolTableBuilderVisitor::visit(CompoundStatement* statement) {
    for (int i = 0; i < statement->n_statements(); ++i) {
        statement->getStatement(i)->accept(this);
    }
}

void SymbolTableBuilderVisitor::visit(WhileStatement* statement) {}
void SymbolTableBuilderVisitor::visit(Expression* expression) {}

void SymbolTableBuilderVisitor::visit(LogicalNotExpression* expression) {
    expression->getExpression()->accept(this);
}

void SymbolTableBuilderVisitor::visit(BitwiseNotExpression* expression) {
    expression->getExpression()->accept(this);
}

void SymbolTableBuilderVisitor::visit(AddressOfExpression* expression) {
    expression->getExpression()->accept(this);
}

void SymbolTableBuilderVisitor::visit(UnaryMinusExpression* expression) {
    expression->getExpression()->accept(this);
}

void SymbolTableBuilderVisitor::visit(UnaryPlusExpression* expression) {
    expression->getExpression()->accept(this);
}

void SymbolTableBuilderVisitor::visit(DolarExpression* expression) {
    expression->getExpression()->accept(this);
}

void SymbolTableBuilderVisitor::visit(ParenthesisExpression* expression) {
    expression->getExpression()->accept(this);
}

void SymbolTableBuilderVisitor::visit(DereferenceExpression* expression) {
    expression->getExpression()->accept(this);
}

void SymbolTableBuilderVisitor::visit(PreIncrementExpression* expression) {
    expression->getExpression()->accept(this);
}

void SymbolTableBuilderVisitor::visit(PreDecrementExpression* expression) {
    expression->getExpression()->accept(this);
}

void SymbolTableBuilderVisitor::visit(SizeOfExpression* expression) {
    expression->getExpression()->accept(this);
}

void SymbolTableBuilderVisitor::visit(CallExpression* expression) {
    expression->get_expression()->accept(this);

    for (int i = 0; i < expression->n_arguments(); ++i) {
        expression->getArgument(i)->accept(this);
    }
}

void SymbolTableBuilderVisitor::visit(DotExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(ArrowExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(IndexExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(ShiftLeftLogicalExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(ShiftRightLogicalExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(ShiftRightArithmeticExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(BitwiseAndExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(BitwiseXorExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(BitwiseOrExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(TimesExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(DivisionExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(IntegerDivisionExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(ModuloExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(PlusExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(MinusExpression* expression) {}
void SymbolTableBuilderVisitor::visit(LessThanExpression* expression) {}
void SymbolTableBuilderVisitor::visit(GreaterThanExpression* expression) {}
void SymbolTableBuilderVisitor::visit(LessThanOrEqualExpression* expression) {}
void SymbolTableBuilderVisitor::visit(GreaterThanOrEqualExpression* expression) {}

void SymbolTableBuilderVisitor::visit(AssignmentExpression* expression) {
    bool oldCheckingAssignment;

    oldCheckingAssignment = checkingAssignment;
    checkingAssignment = false;

    expression->getRight()->accept(this);

    checkingAssignment = true;
    expression->getLeft()->accept(this);

    checkingAssignment = oldCheckingAssignment;
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

void SymbolTableBuilderVisitor::visit(IdentifierExpression* id) {
    if (checkingAssignment) {
        if (symbolTable->hasLocalVariableOrParameter(id->getName()) == nullptr) {
            LocalVariable* var = new LocalVariable(id->getNameAsToken());
            symbolTable->addLocalVariable(var);
            currentDef->addLocalVariable(var);
        }
    } else {
        if (symbolTable->hasLocalVariableOrParameter(id->getName()) == nullptr) {
            std::cout << "error: undefined variable '" << id->getName() << "'\n";
        }
    }
}
