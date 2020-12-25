#include <iostream>
#include <sstream>

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
    logger = nullptr;
    classIdCounter = 0;
    defIdCounter = 0;
    pass = 0;
}

SymbolTableBuilderVisitor::~SymbolTableBuilderVisitor() {

}

void SymbolTableBuilderVisitor::visit(Program *program) {
    std::map<std::string, SourceFile*>::iterator it;

    // First, we add all classes, structs, enums and other named types to
    // the symbol table of a source file.
    for (it = program->begin(); it != program->end(); ++it) {
        it->second->accept(this);
    }

    ++pass;

    // Now that named types are inserted on symbol tables, some form of type
    // checking can be done. But first we link types to their descriptors. The types
    // we are linking to its descriptors are: return types of methods and functions,
    // parameters' types, class variable types, parent class and stuff like that.
    // Note that we are linking only types to its descriptors. The insertion
    // on symbol table comes latter. In other words, we are linking everything now
    // and on later passes we may discard some of these associations. For example,
    // two methods with the same signature or two class variables with same name
    for (it = program->begin(); it != program->end(); ++it) {
        it->second->accept(this);
    }

    ++pass;

    // now we build the symbol table for the function and method bodies
    for (it = program->begin(); it != program->end(); ++it) {
        it->second->accept(this);
    }
}

void SymbolTableBuilderVisitor::visit(SourceFile* file) {
    currentSourceFile = file;

    if (pass == 0) {
        file->setSymbolTable(pushSymbolTable());

        for (int i = 0; i < file->n_classes(); ++i) {
            file->getClass(i)->accept(this);
        }

        popSymbolTable();
    } else if (pass == 1) {
        pushSymbolTable(file->getSymbolTable());

        for (int i = 0; i < file->n_classes(); ++i) {
            file->getClass(i)->accept(this);
        }

        for (int i = 0; i < file->n_defs(); ++i) {
            file->getDef(i)->accept(this);
        }

        popSymbolTable();
    } else {
        std::cout << "Building SymbolTable for file '" << file->getPath() << "'\n";

        currentSourceFile = file;
        pushSymbolTable(file->getSymbolTable());

        for (int i = 0; i < file->n_classes(); ++i) {
            file->getClass(i)->accept(this);
        }

        for (int i = 0; i < file->n_defs(); ++i) {
            file->getDef(i)->accept(this);
        }

        popSymbolTable();
    }
}

void SymbolTableBuilderVisitor::visit(Import* import) {

}

void SymbolTableBuilderVisitor::visit(Class* klass) {
    std::stringstream ss;
    std::string name;
    Symbol* symbol;

    currentClass = klass;
    symbol = nullptr;
    name = klass->getName();

    if (pass == 0) {
        symbol = symbolTable->hasLocal(name);

        if (symbol != nullptr) {
            std::cout << "Error: class '" << name << "' already declared. First occurence on line " << symbol->getLine();
            exit(0);
        } else {
            ss << "Adding class '" << name << "' to source file " << currentSourceFile->getPath();
            log(ss);
            symbolTable->add(klass);
            klass->setId(classIdCounter++);
        }
    } else if (pass == 1) {
        if (klass->hasSuperClass()) {
            klass->getSuperClass()->accept(this);
        }

        klass->getSelfType()->accept(this);
        klass->setSymbolTable(pushSymbolTable());

        for (int i = 0; i < klass->n_variables(); ++i) {
            klass->getVariable(i)->accept(this);
        }

        for (int i = 0; i < klass->n_methods(); ++i) {
            klass->getMethod(i)->accept(this);
        }

        popSymbolTable();
    } else if (pass == 2) {
        pushSymbolTable(klass->getSymbolTable());

        for (int i = 0; i < klass->n_methods(); ++i) {
            klass->getMethod(i)->accept(this);
        }

        popSymbolTable();
    }
}

void SymbolTableBuilderVisitor::visit(Struct* s) {

}

void SymbolTableBuilderVisitor::visit(Def* def) {
    std::stringstream ss;

    currentDef = def;

    if (pass == 1) {
        Symbol* symbol = nullptr;

        if (def->isMethod()) {
            symbol = symbolTable->hasMethod(def);
        } else {
            symbol = symbolTable->hasLocalFunction(def);
        }

        if (symbol != nullptr) {
            std::cout << "error def: '" << def->getName() << "' already declared. First occurence on line " << symbol->getLine();
            exit(0);
        } else {
            ss << "Adding function '" << def->getName() << "' to source file " << currentSourceFile->getPath();
            log(ss);
            symbolTable->add(def);
        }

        symbolTable->add(def);

        def->setId(defIdCounter++);
        def->getReturnType()->accept(this);
        def->setSymbolTable(pushSymbolTable());

        for (int i = 0; i < def->n_parameters(); ++i) {
            def->getParameter(i)->accept(this);
        }

        popSymbolTable();
    } else if (pass == 2) {
        pushSymbolTable(def->getSymbolTable());
        def->getStatements()->accept(this);
        popSymbolTable();
    }
}

void SymbolTableBuilderVisitor::visit(Parameter* parameter) {
    symbolTable->add(parameter);
    parameter->getType()->accept(this);
}

void SymbolTableBuilderVisitor::visit(Variable* variable) {

}

void SymbolTableBuilderVisitor::visit(LocalVariable* variable) {

}

void SymbolTableBuilderVisitor::visit(GlobalVariable* variable) {

}

void SymbolTableBuilderVisitor::visit(ClassVariable *variable) {
    symbolTable->add(variable);
    variable->getType()->accept(this);
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

void SymbolTableBuilderVisitor::visit(FunctionType *type) {
    for (int i = 0; type->n_types(); ++i) {
        type->getParameter(i)->accept(this);
    }
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

    statement->setLiveVariables(symbolTable->getDefVariables());
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
        setLastType(id->getType());
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
    int idx = -1;
    Symbol* sym = nullptr;
    IdentifierExpression* id = nullptr;
    DotExpression* dot = nullptr;
    Expression* expr;
    Type* t = nullptr;
    std::vector<Type*> argTypes;

    expression->getExpression()->accept(this);
    t = lastType;

    for (int i = 0; i < expression->n_arguments(); ++i) {
        expression->getArgument(i)->accept(this);
        argTypes.push_back(lastType);
    }

    expr = expression->getExpression();
    if (expr->getKind() == AST_DOT) {
        dot = (DotExpression*) expression->getExpression();
        id = (IdentifierExpression*) dot->getRight();
        sym = id->getSymbol();

        if (sym->isOverloaded()) {
            idx = sym->getOverloadedDescriptorIndex(argTypes);
            id->setIdxOverloaded(idx);
        }
    } else if (expr->getKind() == AST_IDENTIFIER) {
        id = (IdentifierExpression*) expr;
        sym = id->getSymbol();

        // constructor calls
        if (sym->getKind() == SYMBOL_CLASS) {
            Class* klass = (Class*) sym->getDescriptor();

            sym = klass->getSymbolTable()->has("init");
            id->setSymbol(sym);

            if (sym->isOverloaded()) {
                idx = sym->getOverloadedDescriptorIndex(argTypes);
                id->setIdxOverloaded(idx);
            }

            expression->setConstructorFlag(true);
        } else if (sym->isOverloaded()) {
            idx = sym->getOverloadedDescriptorIndex(argTypes);
            id->setIdxOverloaded(idx);
        }
    }

    expression->setType(t->clone());
    setLastType(expression->getType());
}

void SymbolTableBuilderVisitor::visit(DotExpression* expression) {
    NamedType* t = nullptr;
    SymbolTable* s = nullptr;

    expression->getLeft()->accept(this);
    t = (NamedType*) lastType;
    s = t->getSymbolTable();

    pushSymbolTable(s);
    expression->getRight()->accept(this);
    setLastType(expression->getRight()->getType());
    popSymbolTable();
}

void SymbolTableBuilderVisitor::visit(ArrowExpression* expression) {
    PointerType* ptr = nullptr;
    NamedType* named = nullptr;
    SymbolTable* s = nullptr;

    expression->getLeft()->accept(this);

    ptr = (PointerType*) lastType;
    named = (NamedType*) ptr->getSubtype();
    s = named->getSymbolTable();

    checkingAssignment = false;
    pushSymbolTable(s);
    expression->getRight()->accept(this);
    setLastType(expression->getRight()->getType());
    popSymbolTable();
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
    setLastType(type);
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
    setLastType(type);
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
    setLastType(type);
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
    setLastType(type);
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
    setLastType(type);
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
    setLastType(type);
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
    setLastType(type);
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
    setLastType(type);
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
    setLastType(type);
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
    setLastType(type);
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
    setLastType(type);
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
    setLastType(type);
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
    setLastType(expression->getType());
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
    setLastType(expression->getType());
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
    setLastType(expression->getType());
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
    setLastType(expression->getType());
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
    setLastType(expression->getType());
}

void SymbolTableBuilderVisitor::visit(LogicalAndExpression *expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    expression->setType(new BoolType());
    setLastType(expression->getType());
}

void SymbolTableBuilderVisitor::visit(LogicalOrExpression *expression) {
    Type* left;
    Type* right;
    Type* type;

    expression->getLeft()->accept(this);
    left = lastType;

    expression->getRight()->accept(this);
    right = lastType;

    expression->setType(new BoolType());
    setLastType(expression->getType());
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
    setLastType(expression->getType());
}

void SymbolTableBuilderVisitor::visit(AssignmentExpression* expression) {
    bool oldCheckingAssignment;

    oldCheckingAssignment = checkingAssignment;
    checkingAssignment = false;

    expression->getRight()->accept(this);

    checkingAssignment = true;
    expression->getLeft()->accept(this);
    expression->setType(lastType->clone());
    setLastType(expression->getType());

    // checks if it is a constructor call
    if (expression->getRight()->getKind() == AST_CALL) {
        CallExpression* call = (CallExpression*) expression->getRight();

        expression->setConstructorFlag(call->getConstructorFlag());
    }

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
    setLastType(expression->getType());
}

void SymbolTableBuilderVisitor::visit(LiteralStringExpression* expression) {
    expression->setType((new PointerType(new CharType())));
    setLastType(expression->getType());
}

void SymbolTableBuilderVisitor::visit(LiteralCharExpression* expression) {
    expression->setType(new CharType());
    setLastType(expression->getType());
}

void SymbolTableBuilderVisitor::visit(LiteralFloatExpression* expression) {
    expression->setType(new FloatType());
    setLastType(expression->getType());
}

void SymbolTableBuilderVisitor::visit(LiteralDoubleExpression* expression) {
    expression->setType(new DoubleType());
    setLastType(expression->getType());
}

void SymbolTableBuilderVisitor::visit(LiteralSymbolExpression* expression) {
    expression->setType(new SymbolType());
    setLastType(expression->getType());
}

void SymbolTableBuilderVisitor::visit(LiteralBoolExpression* expression) {
    expression->setType(new BoolType());
    setLastType(expression->getType());
}

void SymbolTableBuilderVisitor::visit(LiteralNullExpression *expression) {
    expression->setType(new PointerType(new VoidType()));
    setLastType(expression->getType());
}

void SymbolTableBuilderVisitor::visit(ListExpression* list) {

}

void SymbolTableBuilderVisitor::visit(ArrayExpression* array) {

}

void SymbolTableBuilderVisitor::visit(IdentifierExpression* id) {
    Symbol* symbol = nullptr;

    if (id->hasAlias()) {
        Import* i = currentSourceFile->getImportWithAlias(id->getAlias());
        SourceFile* f = i->getSourceFile();
        pushSymbolTable(f->getSymbolTable());
    }

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
            setLastType(id->getType());
        } else {
            id->setSymbol(symbol);
            id->setType(symbol->getType()->clone());
            setLastType(id->getType());

            // check types here maybe?
        }
    } else {
        symbol = symbolTable->has(id->getName());

        if (symbol == nullptr) {
            std::cout << currentSourceFile->getPath() << ":" << id->getNameAsToken().getLine() << ":" << id->getNameAsToken().getColumn() << ":";
            std::cout << " error: '" << id->getName() << "' not defined in this scope\n";
            exit(0);
        } else {
            id->setSymbol(symbol);
            id->setType(symbol->getType()->clone());
            setLastType(id->getType());
        }
    }

    if (id->hasAlias()) {
        popSymbolTable();
    }
}

void SymbolTableBuilderVisitor::addGlobalVariables(SourceFile* sourceFile) {
    std::stringstream ss;
    Symbol* symbol;

    for (int i = 0; i < sourceFile->n_global_variables(); ++i) {
        std::string name = sourceFile->getGlobalVariable(i)->getName();
        symbol = symbolTable->hasLocal(name);

        if (symbol != nullptr) {
            std::cout << "error global variable: '" << name << "' already declared. First occurence on line " << symbol->getLine();
            exit(0);
        } else {
            ss << "Adding global variable '" << name << "' to source file " << sourceFile->getPath();
            log(ss);
            symbolTable->add(sourceFile->getGlobalVariable(i));
        }
    }
}

void SymbolTableBuilderVisitor::addGlobalConstants(SourceFile *sourceFile) {
    std::stringstream ss;
    Symbol* symbol;

    for (int i = 0; i < sourceFile->n_global_constants(); ++i) {
        std::string name = sourceFile->getGlobalConstant(i)->getName();
        symbol = symbolTable->hasLocal(name);

        if (symbol != nullptr) {
            std::cout << "error gconst: '" << name << "' already declared. First occurence on line " << symbol->getLine();
            exit(0);
        } else {
            ss << "Adding global constant '" << name << "' to source file " << sourceFile->getPath();
            log(ss);
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

void SymbolTableBuilderVisitor::setLastType(Type *type) {
    lastType = type;

    if (type != nullptr) {
        type->accept(this);
    }
}

void SymbolTableBuilderVisitor::log(std::stringstream& msg) {
    if (logger != nullptr) {
        logger->log(LOG_INTERNAL_SYMBOL_TABLE, msg.str());
    }

    msg.str("");
}

Logger *SymbolTableBuilderVisitor::getLogger() const {
    return logger;
}

void SymbolTableBuilderVisitor::setLogger(Logger *value) {
    logger = value;
}
