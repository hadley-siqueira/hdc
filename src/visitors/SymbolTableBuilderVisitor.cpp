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
    currentSourceFile = file;

    // add functions to the symbolTable
    for (int i = 0; i < file->n_defs(); ++i) {
        symbolTable->addDef(file->getDef(i));
    }

    // add classes
    for (int i = 0; i < file->n_classes(); ++i) {
        symbolTable->addClass(file->getClass(i));
    }

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
    expression->getExpression()->accept(this);

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

void SymbolTableBuilderVisitor::visit(MinusExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(LessThanExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(GreaterThanExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(LessThanOrEqualExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(EqualExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(NotEqualExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(GreaterThanOrEqualExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(AssignmentExpression* expression) {
    bool oldCheckingAssignment;

    oldCheckingAssignment = checkingAssignment;
    checkingAssignment = false;

    expression->getRight()->accept(this);

    checkingAssignment = true;
    expression->getLeft()->accept(this);

    checkingAssignment = oldCheckingAssignment;
}

void SymbolTableBuilderVisitor::visit(BitwiseAndAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(BitwiseXorAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(BitwiseOrAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(BitwiseNotAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(DivisionAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(IntegerDivisionAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(MinusAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(ModuloAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(PlusAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(TimesAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(SllAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(SraAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(SrlAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(SpecialAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    expression->getRight()->accept(this);
}

void SymbolTableBuilderVisitor::visit(LiteralIntegerExpression* expression) {}

void SymbolTableBuilderVisitor::visit(LiteralStringExpression* expression) {

}

void SymbolTableBuilderVisitor::visit(IdentifierExpression* id) {
    Symbol* symbol;

    if (checkingAssignment) {
        symbol = symbolTable->hasLocalVariableOrParameter(id->getName());

        if (symbol == nullptr) {
            LocalVariable* var = new LocalVariable(id->getNameAsToken());
            symbol = symbolTable->addLocalVariable(var);
            currentDef->addLocalVariable(var);
            std::cout << "Adding variable: " << id->getName() << std::endl;
        }

        id->setSymbol(symbol);
    } else {
        symbol = symbolTable->hasLocalVariableOrParameter(id->getName());

        if (symbol == nullptr) {
            std::cout << "error: undefined variable '" << id->getName() << "'\n";
        } else {
            id->setSymbol(symbol);
        }
    }
}

void SymbolTableBuilderVisitor::visit(IfStatement* statement) {
    SymbolTable* oldSymbolTable;

    oldSymbolTable = symbolTable;
    symbolTable = new SymbolTable(symbolTable);
    statement->setSymbolTable(symbolTable);
    statement->getExpression()->accept(this);
    statement->getStatements()->accept(this);

    symbolTable = oldSymbolTable;

    if (statement->getElifStatement()) {
        statement->getElifStatement()->accept(this);
    } else if (statement->getElseStatement()) {
        statement->getElseStatement()->accept(this);
    }
}

void SymbolTableBuilderVisitor::visit(ElifStatement* statement) {
    SymbolTable* oldSymbolTable;

    oldSymbolTable = symbolTable;
    symbolTable = new SymbolTable(symbolTable);
    statement->setSymbolTable(symbolTable);
    statement->getExpression()->accept(this);
    statement->getStatements()->accept(this);

    symbolTable = oldSymbolTable;

    if (statement->getElifStatement()) {
        statement->getElifStatement()->accept(this);
    } else if (statement->getElseStatement()) {
        statement->getElseStatement()->accept(this);
    }
}

void SymbolTableBuilderVisitor::visit(ElseStatement* statement) {
    SymbolTable* oldSymbolTable;

    oldSymbolTable = symbolTable;
    symbolTable = new SymbolTable(symbolTable);
    statement->setSymbolTable(symbolTable);
    statement->getStatements()->accept(this);

    symbolTable = oldSymbolTable;
}

void SymbolTableBuilderVisitor::visit(ReturnStatement* statement) {

}
