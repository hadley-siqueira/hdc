#include "visitors/ast/IRBuilderVisitor.h"
#include "ast/AST.h"

using namespace hdc;

IRBuilderVisitor::IRBuilderVisitor() {
    temporaryCounter = 0;
    lastTemporary = nullptr;
}

IRTemporary *IRBuilderVisitor::newTemporary() {
    lastTemporary = new IRTemporary(temporaryCounter);
    temporaryCounter += 1;

    return lastTemporary;
}

IRLabel* IRBuilderVisitor::newLabel() {
    std::string s = "L";
    s = s + std::to_string(labelCounter);
    labelCounter += 1;
    return new IRLabel(s);
}

void IRBuilderVisitor::visit(SourceFile* file) {
    IRSourceFile* ir;

    ir = new IRSourceFile(file);
    currentSourceFile = ir;

    for (int i = 0; i <file->n_defs(); ++i) {
        file->getDef(i)->accept(this);
    }
}

void IRBuilderVisitor::visit(Import* import) { }

void IRBuilderVisitor::visit(Class* klass) { }
void IRBuilderVisitor::visit(Struct* s) { }

void IRBuilderVisitor::visit(Def* def) {
    IRFunction* ir;

    ir = new IRFunction(def);
    currentFunction = ir;

    def->getStatements()->accept(this);
}

/* Variables */
void IRBuilderVisitor::visit(Parameter* parameter) { }
void IRBuilderVisitor::visit(Variable* variable) { }
void IRBuilderVisitor::visit(LocalVariable* variable) { }
void IRBuilderVisitor::visit(GlobalVariable* variable) { }

/* Constants */
void IRBuilderVisitor::visit(Constant* c) { }
void IRBuilderVisitor::visit(GlobalConstant* c) { }

/* Types */
void IRBuilderVisitor::visit(Type* type) { }
void IRBuilderVisitor::visit(IntType* type) { }
void IRBuilderVisitor::visit(UIntType* type) { }
void IRBuilderVisitor::visit(ShortType* type) { }
void IRBuilderVisitor::visit(UShortType* type) { }
void IRBuilderVisitor::visit(LongType* type) { }
void IRBuilderVisitor::visit(ULongType* type) { }
void IRBuilderVisitor::visit(CharType* type) { }
void IRBuilderVisitor::visit(UCharType* type) { }
void IRBuilderVisitor::visit(FloatType* type) { }
void IRBuilderVisitor::visit(DoubleType* type) { }
void IRBuilderVisitor::visit(VoidType* type) { }
void IRBuilderVisitor::visit(BoolType* type) { }
void IRBuilderVisitor::visit(SymbolType* type) { }
void IRBuilderVisitor::visit(Int8Type* type) { }
void IRBuilderVisitor::visit(Int16Type* type) { }
void IRBuilderVisitor::visit(Int32Type* type) { }
void IRBuilderVisitor::visit(Int64Type* type) { }
void IRBuilderVisitor::visit(UInt8Type* type) { }
void IRBuilderVisitor::visit(UInt16Type* type) { }
void IRBuilderVisitor::visit(UInt32Type* type) { }
void IRBuilderVisitor::visit(UInt64Type* type) { }
void IRBuilderVisitor::visit(PointerType* type) { }
void IRBuilderVisitor::visit(NamedType* type) { }

/* Statements */
void IRBuilderVisitor::visit(Statement* statement) { }

void IRBuilderVisitor::visit(CompoundStatement* statement) {
    if (statement->n_statements() > 0) {
        for (int i = 0; i < statement->n_statements(); ++i) {
            statement->getStatement(i)->accept(this);
        }
    }
}

void IRBuilderVisitor::visit(WhileStatement* statement) {
    IRLabel* labelBefore;
    IRLabel* labelAfter;

    labelBefore = newLabel();
    labelAfter = newLabel();

    currentFunction->add(labelBefore);
    statement->getExpression()->accept(this);
    //currentFunction->addIR(new IRIFz(lastTemporary))
}

void IRBuilderVisitor::visit(ForStatement* statement) { }
void IRBuilderVisitor::visit(ForEachStatement* statement) { }
void IRBuilderVisitor::visit(IfStatement* statement) { }
void IRBuilderVisitor::visit(ElifStatement* statement) { }
void IRBuilderVisitor::visit(ElseStatement* statement) { }
void IRBuilderVisitor::visit(ReturnStatement* statement) { }

/* Expressions */
void IRBuilderVisitor::visit(Expression* expression) { }

/* Unary Expressions */
void IRBuilderVisitor::visit(LogicalNotExpression* expression) { }
void IRBuilderVisitor::visit(BitwiseNotExpression* expression) { }
void IRBuilderVisitor::visit(AddressOfExpression* expression) { }
void IRBuilderVisitor::visit(UnaryMinusExpression* expression) { }
void IRBuilderVisitor::visit(UnaryPlusExpression* expression) { }
void IRBuilderVisitor::visit(DolarExpression* expression) { }
void IRBuilderVisitor::visit(AtExpression* expression) { }
void IRBuilderVisitor::visit(ParenthesisExpression* expression) { }
void IRBuilderVisitor::visit(DereferenceExpression* expression) { }
void IRBuilderVisitor::visit(PreIncrementExpression* expression) { }
void IRBuilderVisitor::visit(PreDecrementExpression* expression) { }
void IRBuilderVisitor::visit(SizeOfExpression* expression) { }

/* Binary Expresisons */
void IRBuilderVisitor::visit(CallExpression* expression) { }
void IRBuilderVisitor::visit(DotExpression* expression) { }
void IRBuilderVisitor::visit(ArrowExpression* expression) { }
void IRBuilderVisitor::visit(IndexExpression* expression) { }

void IRBuilderVisitor::visit(ShiftLeftLogicalExpression* expression) { }
void IRBuilderVisitor::visit(ShiftRightLogicalExpression* expression) { }
void IRBuilderVisitor::visit(ShiftRightArithmeticExpression* expression) { }

void IRBuilderVisitor::visit(BitwiseAndExpression* expression) { }
void IRBuilderVisitor::visit(BitwiseXorExpression* expression) { }
void IRBuilderVisitor::visit(BitwiseOrExpression* expression) { }

void IRBuilderVisitor::visit(TimesExpression* expression) { }
void IRBuilderVisitor::visit(DivisionExpression* expression) { }
void IRBuilderVisitor::visit(IntegerDivisionExpression* expression) { }
void IRBuilderVisitor::visit(ModuloExpression* expression) { }

void IRBuilderVisitor::visit(PlusExpression* expression) {
    IRTemporary* dst;
    IRTemporary* src1;
    IRTemporary* src2;
    IRAdd* ir;

    expression->getLeft()->accept(this);
    src1 = lastTemporary;

    expression->getRight()->accept(this);
    src2 = lastTemporary;

    dst = newTemporary();
    ir = new IRAdd(dst, src1, src2);
    /*int src2;
    int dst;

    expression->getLeft()->accept(this);
    src1 = lastTemporary;

    expression->getRight()->accept(this);
    src2 = lastTemporary;

    dst = newTemporary();
    emit(TAC_ADD, dst, src1, src2);*/
}

void IRBuilderVisitor::visit(MinusExpression* expression) { }

void IRBuilderVisitor::visit(LessThanExpression* expression) { }
void IRBuilderVisitor::visit(GreaterThanExpression* expression) { }
void IRBuilderVisitor::visit(LessThanOrEqualExpression* expression) { }
void IRBuilderVisitor::visit(GreaterThanOrEqualExpression* expression) { }
void IRBuilderVisitor::visit(EqualExpression* expression) { }
void IRBuilderVisitor::visit(NotEqualExpression* expression) { }

void IRBuilderVisitor::visit(AssignmentExpression* expression) { }
void IRBuilderVisitor::visit(BitwiseAndAssignmentExpression* expression) { }
void IRBuilderVisitor::visit(BitwiseXorAssignmentExpression* expression) { }
void IRBuilderVisitor::visit(BitwiseOrAssignmentExpression* expression) { }
void IRBuilderVisitor::visit(BitwiseNotAssignmentExpression* expression) { }
void IRBuilderVisitor::visit(DivisionAssignmentExpression* expression) { }
void IRBuilderVisitor::visit(IntegerDivisionAssignmentExpression* expression) { }
void IRBuilderVisitor::visit(MinusAssignmentExpression* expression) { }
void IRBuilderVisitor::visit(ModuloAssignmentExpression* expression) { }
void IRBuilderVisitor::visit(PlusAssignmentExpression* expression) { }
void IRBuilderVisitor::visit(TimesAssignmentExpression* expression) { }
void IRBuilderVisitor::visit(SllAssignmentExpression* expression) { }
void IRBuilderVisitor::visit(SraAssignmentExpression* expression) { }
void IRBuilderVisitor::visit(SrlAssignmentExpression* expression) { }
void IRBuilderVisitor::visit(SpecialAssignmentExpression* expression) { }

/* Literals */
void IRBuilderVisitor::visit(LiteralIntegerExpression* expression) { }
void IRBuilderVisitor::visit(LiteralStringExpression* expression) { }
void IRBuilderVisitor::visit(LiteralCharExpression* expression) { }
void IRBuilderVisitor::visit(LiteralFloatExpression* expression) { }
void IRBuilderVisitor::visit(LiteralDoubleExpression* expression) { }
void IRBuilderVisitor::visit(LiteralSymbolExpression* expression) { }
void IRBuilderVisitor::visit(LiteralBoolExpression* expression) { }
void IRBuilderVisitor::visit(ListExpression* list) { }
void IRBuilderVisitor::visit(ArrayExpression* array) { }

void IRBuilderVisitor::visit(IdentifierExpression* id) { }
