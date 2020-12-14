#include <iostream>
#include "visitors/SymbolTableBuilderVisitor.h"
#include "ast/AST.h"

using namespace hdc;

/* Constructors */
SymbolTableBuilderVisitor::SymbolTableBuilderVisitor() {
    symbolTable = nullptr;
    currentClass = nullptr;
    checkingAssignment = false;
    checkingNamedType = false;
    lastType = nullptr;
}

SymbolTableBuilderVisitor::~SymbolTableBuilderVisitor() {

}

void SymbolTableBuilderVisitor::visit(Program *program) {
    std::map<std::string, SourceFile*>::iterator it;

    for (it = program->begin(); it != program->end(); ++it) {
        buildInitialSymbolTable(it->second);
    }

    for (it = program->begin(); it != program->end(); ++it) {
        it->second->accept(this);
    }
}

void SymbolTableBuilderVisitor::visit(SourceFile* file) {
    std::cout << "Building SymbolTable for file '" << file->getPath() << "'\n";

    currentSourceFile = file;
    pushSymbolTable(file->getSymbolTable());


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
    currentClass = klass;
    klass->setSymbolTable(pushSymbolTable());

    for (int i = 0; i < klass->n_methods(); ++i) {
        klass->getMethod(i)->getReturnType()->accept(this);
        symbolTable->add(klass->getMethod(i));
    }

    for (int i = 0; i < klass->n_variables(); ++i) {
        klass->getVariable(i)->getType()->accept(this);
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

    def->getReturnType()->accept(this);
    def->setSymbolTable(pushSymbolTable());

    for (int i = 0; i < def->n_parameters(); ++i) {
        symbolTable->add(def->getParameter(i));
        def->getParameter(i)->getType()->accept(this);
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

void SymbolTableBuilderVisitor::visit(PointerType* type) {
    type->getSubtype()->accept(this);
}

void SymbolTableBuilderVisitor::visit(NamedType* type) {
    checkingNamedType = true;
    type->getName()->accept(this);
    checkingNamedType = false;
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
    Variable* v;

    id = (IdentifierExpression*) expression->getExpression();
    name = id->getName();
    symbol = symbolTable->hasClassVariable(name);

    if (symbol != nullptr) {
        id->setSymbol(symbol);
        v = currentClass->getVariable(id->getName());
        id->setType(v->getType()->clone());
        lastType = id->getType();
    }

    expression->setType(lastType->clone());
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
// obj.m(...)
void SymbolTableBuilderVisitor::visit(DotExpression* expression) {
    NamedType* t;
    SymbolTable* s;

    expression->getLeft()->accept(this);

    t = (NamedType*) lastType;

    if (t != nullptr) {
       s = t->getSymbolTable();

       if (s != nullptr) {
        std::cout << "YEAH "; s->dump();
       }
    }

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
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    type = typeCoercion(left, right);
    expression->setType(type);
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(ShiftRightLogicalExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    type = typeCoercion(left, right);
    expression->setType(type);
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(ShiftRightArithmeticExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    type = typeCoercion(left, right);
    expression->setType(type);
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(BitwiseAndExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    type = typeCoercion(left, right);
    expression->setType(type);
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(BitwiseXorExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    type = typeCoercion(left, right);
    expression->setType(type);
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(BitwiseOrExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    type = typeCoercion(left, right);
    expression->setType(type);
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(TimesExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    type = typeCoercion(left, right);
    expression->setType(type);
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(DivisionExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    type = typeCoercion(left, right);
    expression->setType(type);
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(IntegerDivisionExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    type = typeCoercion(left, right);
    expression->setType(type);
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(ModuloExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    type = typeCoercion(left, right);
    expression->setType(type);
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(PlusExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    type = typeCoercion(left, right);
    expression->setType(type);
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(MinusExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    type = typeCoercion(left, right);
    expression->setType(type);
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(LessThanExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    expression->setType(new BoolType());
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(GreaterThanExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    expression->setType(new BoolType());
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(LessThanOrEqualExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    expression->setType(new BoolType());
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(EqualExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    expression->setType(new BoolType());
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(NotEqualExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    expression->setType(new BoolType());
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(GreaterThanOrEqualExpression* expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    expression->setType(new BoolType());
    lastType = type;
}

void SymbolTableBuilderVisitor::visit(AssignmentExpression* expression) {
    bool oldCheckingAssignment;

    oldCheckingAssignment = checkingAssignment;
    checkingAssignment = false;

    expression->getRight()->accept(this);

    checkingAssignment = true;
    expression->getLeft()->accept(this);
    expression->setType(lastType->clone());
    lastType = expression->getType();

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

void SymbolTableBuilderVisitor::visit(LiteralIntegerExpression* expression) {
    expression->setType(new IntType());
    lastType = expression->getType();
}

void SymbolTableBuilderVisitor::visit(LiteralStringExpression* expression) {
    expression->setType((new PointerType(new CharType())));
    lastType = expression->getType();
}

void SymbolTableBuilderVisitor::visit(LiteralCharExpression* expression) {
    expression->setType(new CharType());
    lastType = expression->getType();
}

void SymbolTableBuilderVisitor::visit(LiteralFloatExpression* expression) {
    expression->setType(new FloatType());
    lastType = expression->getType();
}

void SymbolTableBuilderVisitor::visit(LiteralDoubleExpression* expression) {
    expression->setType(new DoubleType());
    lastType = expression->getType();
}

void SymbolTableBuilderVisitor::visit(LiteralSymbolExpression* expression) {
    expression->setType(new SymbolType());
    lastType = expression->getType();
}

void SymbolTableBuilderVisitor::visit(LiteralBoolExpression* expression) {
    expression->setType(new BoolType());
    lastType = expression->getType();
}

void SymbolTableBuilderVisitor::visit(LiteralNullExpression *expression) {
    expression->setType(new PointerType(new VoidType()));
    lastType = expression->getType();
}

void SymbolTableBuilderVisitor::visit(ListExpression* list) {

}

void SymbolTableBuilderVisitor::visit(ArrayExpression* array) {

}

void SymbolTableBuilderVisitor::visit(IdentifierExpression* id) {
    Symbol* symbol;

    if (checkingNamedType) {
        symbol = symbolTable->has(id->getName());

        if (symbol != nullptr) {
            if (symbol->getKind() == SYMBOL_CLASS) {
                id->setSymbol(symbol);
            }
        }
    } else if (checkingAssignment) {
        symbol = symbolTable->hasLocalVariableOrParameter(id->getName());

        if (symbol == nullptr) {
            LocalVariable* var = new LocalVariable(id->getNameAsToken());
            var->setType(lastType->clone());
            symbol = symbolTable->add(var);
            currentDef->addLocalVariable(var);
            id->setType(lastType->clone());
            id->setSymbol(symbol);
        } else {
            id->setSymbol(symbol);

            // check types here maybe?
        }
    } else {
        symbol = symbolTable->has(id->getName());

        if (symbol == nullptr) {
            std::cout << "error: '" << id->getName() << "' not defined in this scope\n";
        } else {
            id->setSymbol(symbol);
            id->setType(symbol->getType()->clone());
            lastType = id->getType();
        }
    }
}

void SymbolTableBuilderVisitor::buildInitialSymbolTable(SourceFile* sourceFile) {
    Symbol* symbol;

    currentSourceFile = sourceFile;
    sourceFile->setSymbolTable(pushSymbolTable());

    std::cout << "Building initial SymbolTable for file '" << sourceFile->getPath() << "'\n";

    for (int i = 0; i < sourceFile->n_defs(); ++i) {
        std::string name = sourceFile->getDef(i)->getName();
        symbol = symbolTable->hasLocal(name);

        if (symbol != nullptr) {
            std::cout << "error def: '" << name << "' already declared. First occurence on line " << symbol->getLine();
            exit(0);
        } else {
            symbolTable->add(sourceFile->getDef(i));
        }
    }

    for (int i = 0; i < sourceFile->n_classes(); ++i) {
        std::string name = sourceFile->getClass(i)->getName();
        symbol = symbolTable->hasLocal(name);

        if (symbol != nullptr) {
            std::cout << "error class: '" << name << "' already declared. First occurence on line " << symbol->getLine();
            exit(0);
        } else {
            symbolTable->add(sourceFile->getClass(i));
        }
    }

    for (int i = 0; i < sourceFile->n_global_variables(); ++i) {
        std::string name = sourceFile->getGlobalVariable(i)->getName();
        symbol = symbolTable->hasLocal(name);

        if (symbol != nullptr) {
            std::cout << "error global variable: '" << name << "' already declared. First occurence on line " << symbol->getLine();
            exit(0);
        } else {
            symbolTable->add(sourceFile->getGlobalVariable(i));
        }
    }

    for (int i = 0; i < sourceFile->n_global_constants(); ++i) {
        std::string name = sourceFile->getGlobalConstant(i)->getName();
        symbol = symbolTable->hasLocal(name);

        if (symbol != nullptr) {
            std::cout << "error gconst: '" << name << "' already declared. First occurence on line " << symbol->getLine();
            exit(0);
        } else {
            symbolTable->add(sourceFile->getGlobalVariable(i));
        }
    }

    popSymbolTable();
}

SymbolTable *SymbolTableBuilderVisitor::pushSymbolTable() {
    SymbolTable* old;

    old = symbolTable;
    symbolTableStack.push(symbolTable);
    symbolTable = new SymbolTable(old);

    return symbolTable;
}

SymbolTable *SymbolTableBuilderVisitor::pushSymbolTable(SymbolTable *s) {
    symbolTableStack.push(symbolTable);
    symbolTable = s;

    return symbolTable;
}

void SymbolTableBuilderVisitor::popSymbolTable() {
    symbolTable = nullptr;

    if (symbolTableStack.size() > 0) {
        symbolTable = symbolTableStack.top();
        symbolTableStack.pop();
    }
}

Type *SymbolTableBuilderVisitor::typeCoercion(Type *t1, Type *t2) {
    int r1 = t1->getRank();
    int r2 = t2->getRank();
    Type* t;

    if (r1 > r2) {
        t = t1->clone();
    } else {
        t = t2->clone();
    }

    return t;
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
