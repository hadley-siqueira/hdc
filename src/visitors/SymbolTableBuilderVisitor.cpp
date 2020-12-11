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

SymbolTableBuilderVisitor::~SymbolTableBuilderVisitor() {

}

bool SymbolTableBuilderVisitor::getFirstPass() const {
    return firstPass;
}

void SymbolTableBuilderVisitor::setFirstPass(bool value) {
    firstPass = value;
}

void SymbolTableBuilderVisitor::visit(SourceFile* file) {
    std::cout << "Building SymbolTable for file '" << file->getPath() << "'\n";

    file->setSymbolTable(pushSymbolTable());
    currentSourceFile = file;

    buildInitialSymbolTable(file);

    // add global variables
    // add constants

    for (int i = 0; i < file->n_defs(); ++i) {
        file->getDef(i)->accept(this);
    }

    for (int i = 0; i < file->n_classes(); ++i) {
        file->getClass(i)->accept(this);
    }

    popSymbolTable();
}

void SymbolTableBuilderVisitor::visit(Import* import) {

}

void SymbolTableBuilderVisitor::visit(Class* klass) {
    klass->setSymbolTable(pushSymbolTable());

    for (int i = 0; i < klass->n_methods(); ++i) {
        symbolTable->add(klass->getMethod(i));
    }

    for (int i = 0; i < klass->n_variables(); ++i) {
        symbolTable->add(klass->getVariable(i));
    }

    for (int i = 0; i < klass->n_methods(); ++i) {
        klass->getMethod(i)->accept(this);
    }

    popSymbolTable();
}

void SymbolTableBuilderVisitor::visit(Struct* s) {

}

void SymbolTableBuilderVisitor::visit(Def* def) {
    currentDef = def;

    def->setSymbolTable(pushSymbolTable());

    for (int i = 0; i < def->n_parameters(); ++i) {
        symbolTable->add(def->getParameter(i));
    }

    def->getStatements()->accept(this);
    popSymbolTable();
}

void SymbolTableBuilderVisitor::visit(Parameter* parameter) {}

void SymbolTableBuilderVisitor::visit(Variable* variable) {

}

void SymbolTableBuilderVisitor::visit(LocalVariable* variable) {

}

void SymbolTableBuilderVisitor::visit(GlobalVariable* variable) {

}

void SymbolTableBuilderVisitor::visit(Constant* c) {

}

void SymbolTableBuilderVisitor::visit(GlobalConstant* c) {

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

void SymbolTableBuilderVisitor::visit(NamedType* type) {

}

void SymbolTableBuilderVisitor::visit(Statement* statement) {}

void SymbolTableBuilderVisitor::visit(CompoundStatement* statement) {
    for (int i = 0; i < statement->n_statements(); ++i) {
        statement->getStatement(i)->accept(this);
    }
}

void SymbolTableBuilderVisitor::visit(WhileStatement* statement) {
    statement->setSymbolTable(pushSymbolTable());
    statement->getExpression()->accept(this);
    statement->getStatements()->accept(this);
    popSymbolTable();
}

void SymbolTableBuilderVisitor::visit(ForStatement* statement) {

}

void SymbolTableBuilderVisitor::visit(ForEachStatement* statement) {

}

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

void SymbolTableBuilderVisitor::visit(AtExpression* expression) {
    Symbol* symbol;
    IdentifierExpression* id;
    std::string name;

    id = (IdentifierExpression*) expression->getExpression();
    name = id->getName();
    symbol = symbolTable->hasClassVariable(name);

    if (symbol != nullptr) {
        id->setSymbol(symbol);
    }
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

void SymbolTableBuilderVisitor::visit(LiteralCharExpression* expression) {

}

void SymbolTableBuilderVisitor::visit(LiteralFloatExpression* expression) {

}

void SymbolTableBuilderVisitor::visit(LiteralDoubleExpression* expression) {

}

void SymbolTableBuilderVisitor::visit(LiteralSymbolExpression* expression) {

}

void SymbolTableBuilderVisitor::visit(LiteralBoolExpression* expression) {

}

void SymbolTableBuilderVisitor::visit(ListExpression* list) {

}

void SymbolTableBuilderVisitor::visit(ArrayExpression* array) {

}

void SymbolTableBuilderVisitor::visit(IdentifierExpression* id) {
    Symbol* symbol;

    if (checkingAssignment) {
        symbol = symbolTable->hasLocalVariableOrParameter(id->getName());

        if (symbol == nullptr) {
            LocalVariable* var = new LocalVariable(id->getNameAsToken());
            symbol = symbolTable->add(var);
            currentDef->addLocalVariable(var);
        }

        id->setSymbol(symbol);
    } else {
        symbol = symbolTable->has(id->getName());

        if (symbol == nullptr) {
            std::cout << "error: '" << id->getName() << "' not defined in this scope\n";
        } else {
            id->setSymbol(symbol);
        }
    }
}

void SymbolTableBuilderVisitor::buildInitialSymbolTable(SourceFile* sourceFile) {
    Symbol* symbol;

    for (int i = 0; i < sourceFile->n_defs(); ++i) {
        std::string name = sourceFile->getDef(i)->getName();
        symbol = symbolTable->has(name);

        if (symbol != nullptr) {
            std::cout << "error def: '" << name << "' already declared. First occurence on line " << symbol->getLine();
            exit(0);
        } else {
            symbolTable->add(sourceFile->getDef(i));
        }
    }

    for (int i = 0; i < sourceFile->n_classes(); ++i) {
        std::string name = sourceFile->getClass(i)->getName();
        symbol = symbolTable->has(name);

        if (symbol != nullptr) {
            std::cout << "error class: '" << name << "' already declared. First occurence on line " << symbol->getLine();
            exit(0);
        } else {
            symbolTable->add(sourceFile->getClass(i));
        }
    }

    for (int i = 0; i < sourceFile->n_global_variables(); ++i) {
        std::string name = sourceFile->getGlobalVariable(i)->getName();
        symbol = symbolTable->has(name);

        if (symbol != nullptr) {
            std::cout << "error global variable: '" << name << "' already declared. First occurence on line " << symbol->getLine();
            exit(0);
        } else {
            symbolTable->add(sourceFile->getGlobalVariable(i));
        }
    }

    for (int i = 0; i < sourceFile->n_global_constants(); ++i) {
        std::string name = sourceFile->getGlobalConstant(i)->getName();
        symbol = symbolTable->has(name);

        if (symbol != nullptr) {
            std::cout << "error gconst: '" << name << "' already declared. First occurence on line " << symbol->getLine();
            exit(0);
        } else {
            symbolTable->add(sourceFile->getGlobalVariable(i));
        }
    }
}

SymbolTable *SymbolTableBuilderVisitor::pushSymbolTable() {
    SymbolTable* old;

    old = symbolTable;
    symbolTableStack.push(symbolTable);
    symbolTable = new SymbolTable(old);

    return symbolTable;
}

void SymbolTableBuilderVisitor::popSymbolTable() {
    symbolTable = nullptr;

    if (symbolTableStack.size() > 0) {
        symbolTable = symbolTableStack.top();
        symbolTableStack.pop();
    }
}

void SymbolTableBuilderVisitor::visit(IfStatement* statement) {
    statement->setSymbolTable(pushSymbolTable());
    statement->getExpression()->accept(this);
    statement->getStatements()->accept(this);

    popSymbolTable();

    if (statement->getElifStatement()) {
        statement->getElifStatement()->accept(this);
    } else if (statement->getElseStatement()) {
        statement->getElseStatement()->accept(this);
    }
}

void SymbolTableBuilderVisitor::visit(ElifStatement* statement) {
    statement->setSymbolTable(pushSymbolTable());
    statement->getExpression()->accept(this);
    statement->getStatements()->accept(this);

    popSymbolTable();

    if (statement->getElifStatement()) {
        statement->getElifStatement()->accept(this);
    } else if (statement->getElseStatement()) {
        statement->getElseStatement()->accept(this);
    }
}

void SymbolTableBuilderVisitor::visit(ElseStatement* statement) {
    statement->setSymbolTable(pushSymbolTable());
    statement->getStatements()->accept(this);

    popSymbolTable();
}

void SymbolTableBuilderVisitor::visit(ReturnStatement* statement) {
    if (statement->getExpression() != nullptr) {
        statement->getExpression()->accept(this);
    }
}
