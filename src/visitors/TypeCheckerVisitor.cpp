#include "visitors/TypeCheckerVisitor.h"

using namespace hdc;

TypeCheckerVisitor::TypeCheckerVisitor() {
    this->symbolTable = nullptr;
    this->symbolTableStack = new SymbolTableStack(&this->symbolTable);
    this->lastType = nullptr;
}

TypeCheckerVisitor::~TypeCheckerVisitor() {
    delete symbolTableStack;
}

void TypeCheckerVisitor::visit(SourceFile* file) {
    checkFunctions(file);
}

void TypeCheckerVisitor::visit(Import* import) {}

void TypeCheckerVisitor::visit(Class* klass) {}

void TypeCheckerVisitor::visit(Def* def) {
    symbolTableStack->push(def->getSymbolTable());
    def->getStatements()->accept(this);
    symbolTableStack->pop();
}

/* Variables */
void TypeCheckerVisitor::visit(Parameter* parameter) {}
void TypeCheckerVisitor::visit(Variable* variable) {}
void TypeCheckerVisitor::visit(LocalVariable* variable) {}

/* Types */
void TypeCheckerVisitor::visit(Type* type) {}
void TypeCheckerVisitor::visit(IntType* type) {}
void TypeCheckerVisitor::visit(UIntType* type) {}
void TypeCheckerVisitor::visit(ShortType* type) {}
void TypeCheckerVisitor::visit(UShortType* type) {}
void TypeCheckerVisitor::visit(LongType* type) {}
void TypeCheckerVisitor::visit(ULongType* type) {}
void TypeCheckerVisitor::visit(CharType* type) {}
void TypeCheckerVisitor::visit(UCharType* type) {}
void TypeCheckerVisitor::visit(FloatType* type) {}
void TypeCheckerVisitor::visit(DoubleType* type) {}
void TypeCheckerVisitor::visit(VoidType* type) {}
void TypeCheckerVisitor::visit(BoolType* type) {}
void TypeCheckerVisitor::visit(SymbolType* type) {}
void TypeCheckerVisitor::visit(Int8Type* type) {}
void TypeCheckerVisitor::visit(Int16Type* type) {}
void TypeCheckerVisitor::visit(Int32Type* type) {}
void TypeCheckerVisitor::visit(Int64Type* type) {}
void TypeCheckerVisitor::visit(UInt8Type* type) {}
void TypeCheckerVisitor::visit(UInt16Type* type) {}
void TypeCheckerVisitor::visit(UInt32Type* type) {}
void TypeCheckerVisitor::visit(UInt64Type* type) {}
void TypeCheckerVisitor::visit(PointerType* type) {}

/* Statements */
void TypeCheckerVisitor::visit(Statement* statement) {}
void TypeCheckerVisitor::visit(CompoundStatement* statement) {}
void TypeCheckerVisitor::visit(WhileStatement* statement) {}
void TypeCheckerVisitor::visit(IfStatement* statement) {}
void TypeCheckerVisitor::visit(ElifStatement* statement) {}
void TypeCheckerVisitor::visit(ElseStatement* statement) {}
void TypeCheckerVisitor::visit(ReturnStatement* statement) {}

/* Expressions */
void TypeCheckerVisitor::visit(Expression* expression) {}

/* Unary Expressions */
void TypeCheckerVisitor::visit(LogicalNotExpression* expression) {}
void TypeCheckerVisitor::visit(BitwiseNotExpression* expression) {}
void TypeCheckerVisitor::visit(AddressOfExpression* expression) {}
void TypeCheckerVisitor::visit(UnaryMinusExpression* expression) {}
void TypeCheckerVisitor::visit(UnaryPlusExpression* expression) {}
void TypeCheckerVisitor::visit(DolarExpression* expression) {}
void TypeCheckerVisitor::visit(ParenthesisExpression* expression) {}
void TypeCheckerVisitor::visit(DereferenceExpression* expression) {}
void TypeCheckerVisitor::visit(PreIncrementExpression* expression) {}
void TypeCheckerVisitor::visit(PreDecrementExpression* expression) {}
void TypeCheckerVisitor::visit(SizeOfExpression* expression) {}

/* Binary Expresisons */
void TypeCheckerVisitor::visit(CallExpression* expression) {}
void TypeCheckerVisitor::visit(DotExpression* expression) {}
void TypeCheckerVisitor::visit(ArrowExpression* expression) {}
void TypeCheckerVisitor::visit(IndexExpression* expression) {}

void TypeCheckerVisitor::visit(ShiftLeftLogicalExpression* expression) {}
void TypeCheckerVisitor::visit(ShiftRightLogicalExpression* expression) {}
void TypeCheckerVisitor::visit(ShiftRightArithmeticExpression* expression) {}

void TypeCheckerVisitor::visit(BitwiseAndExpression* expression) {}
void TypeCheckerVisitor::visit(BitwiseXorExpression* expression) {}
void TypeCheckerVisitor::visit(BitwiseOrExpression* expression) {}

void TypeCheckerVisitor::visit(TimesExpression* expression) {}
void TypeCheckerVisitor::visit(DivisionExpression* expression) {}
void TypeCheckerVisitor::visit(IntegerDivisionExpression* expression) {}
void TypeCheckerVisitor::visit(ModuloExpression* expression) {}

void TypeCheckerVisitor::visit(PlusExpression* expression) {}
void TypeCheckerVisitor::visit(MinusExpression* expression) {}

void TypeCheckerVisitor::visit(LessThanExpression* expression) {}
void TypeCheckerVisitor::visit(GreaterThanExpression* expression) {}
void TypeCheckerVisitor::visit(LessThanOrEqualExpression* expression) {}
void TypeCheckerVisitor::visit(GreaterThanOrEqualExpression* expression) {}
void TypeCheckerVisitor::visit(EqualExpression* expression) {}
void TypeCheckerVisitor::visit(NotEqualExpression* expression) {}

void TypeCheckerVisitor::visit(AssignmentExpression* expression) {}
void TypeCheckerVisitor::visit(BitwiseAndAssignmentExpression* expression) {}
void TypeCheckerVisitor::visit(BitwiseXorAssignmentExpression* expression) {}
void TypeCheckerVisitor::visit(BitwiseOrAssignmentExpression* expression) {}
void TypeCheckerVisitor::visit(BitwiseNotAssignmentExpression* expression) {}
void TypeCheckerVisitor::visit(DivisionAssignmentExpression* expression) {}
void TypeCheckerVisitor::visit(IntegerDivisionAssignmentExpression* expression) {}
void TypeCheckerVisitor::visit(MinusAssignmentExpression* expression) {}
void TypeCheckerVisitor::visit(ModuloAssignmentExpression* expression) {}
void TypeCheckerVisitor::visit(PlusAssignmentExpression* expression) {}
void TypeCheckerVisitor::visit(TimesAssignmentExpression* expression) {}
void TypeCheckerVisitor::visit(SllAssignmentExpression* expression) {}
void TypeCheckerVisitor::visit(SraAssignmentExpression* expression) {}
void TypeCheckerVisitor::visit(SrlAssignmentExpression* expression) {}
void TypeCheckerVisitor::visit(SpecialAssignmentExpression* expression) {}

void TypeCheckerVisitor::visit(LiteralIntegerExpression* expression) {
    expression->setType(new IntType());
    lastType = expression->getType();
}

void TypeCheckerVisitor::visit(IdentifierExpression* id) {
    Symbol* symbol;

    symbol = id->getSymbol();

    if (symbol->getKind() == SYMBOL_LOCAL_VARIABLE) {
        LocalVariable* var = (LocalVariable*) symbol->getDescriptor();

        if (var->getType() == nullptr) {
            var->setType(lastType->clone());
        }
    }
}

void TypeCheckerVisitor::checkFunctions(SourceFile* file) {
    for (int i = 0; i < file->n_defs(); ++i) {
        file->getDef(i)->accept(this);
    }
}
