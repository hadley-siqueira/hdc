#include <iostream>

#include "ast/Variable.h"

#include "visitors/ast/IRBuilderVisitor.h"
#include "ast/AST.h"
#include "ir/values/IRConstant.h"

using namespace hdc;

IRBuilderVisitor::IRBuilderVisitor() {
    temporaryCounter = 0;
    labelCounter = 0;
    lastTemporary = nullptr;
    irProgram = new IRProgram();

    checkingAssignment = false;
}

IRProgram *IRBuilderVisitor::getIRProgram() {
    return irProgram;
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

void IRBuilderVisitor::visit(Program *program) {

}

void IRBuilderVisitor::visit(SourceFile* file) {
    IRSourceFile* ir;

    ir = new IRSourceFile(file);
    currentSourceFile = ir;
    irProgram->addIRSourceFile(ir);

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
    currentSourceFile->addFunction(ir);

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

    currentFunction->add(new IRLabelDef(labelBefore));
    statement->getExpression()->accept(this);
    currentFunction->add(new IRIFz(lastTemporary, labelAfter));

    statement->getStatements()->accept(this);
    currentFunction->add(new IRGoto(labelBefore));
    currentFunction->add(new IRLabelDef(labelAfter));
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

void IRBuilderVisitor::visit(ParenthesisExpression* expression) {
    expression->getExpression()->accept(this);
}

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
    currentFunction->add(ir);
}

void IRBuilderVisitor::visit(MinusExpression* expression) {
    IRTemporary* dst;
    IRTemporary* src1;
    IRTemporary* src2;
    IRMinus* ir;

    expression->getLeft()->accept(this);
    src1 = lastTemporary;

    expression->getRight()->accept(this);
    src2 = lastTemporary;

    dst = newTemporary();
    ir = new IRMinus(dst, src1, src2);
    currentFunction->add(ir);
}

void IRBuilderVisitor::visit(LessThanExpression* expression) { }
void IRBuilderVisitor::visit(GreaterThanExpression* expression) { }
void IRBuilderVisitor::visit(LessThanOrEqualExpression* expression) { }
void IRBuilderVisitor::visit(GreaterThanOrEqualExpression* expression) { }
void IRBuilderVisitor::visit(EqualExpression* expression) { }
void IRBuilderVisitor::visit(NotEqualExpression* expression) { }

void IRBuilderVisitor::visit(AssignmentExpression* expression) {
    IRValue* dst;
    IRValue* src;
    bool oldCheckingAssignment;

    oldCheckingAssignment = checkingAssignment;

    checkingAssignment = false;
    expression->getRight()->accept(this);
    src = lastTemporary;

    checkingAssignment = true;
    expression->getLeft()->accept(this);
    dst = lastTemporary;

    currentFunction->add(new IRStore(dst, src));
    checkingAssignment = oldCheckingAssignment;
}

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
void IRBuilderVisitor::visit(LiteralIntegerExpression* expression) {
    Token token;
    IRValue* dst;
    IRValue* src;

    token = expression->get_token();
    dst = newTemporary();
    src = new IRConstant(token);
    currentFunction->add(new IRLoadConstant(dst, src));
}

void IRBuilderVisitor::visit(LiteralStringExpression* expression) { }
void IRBuilderVisitor::visit(LiteralCharExpression* expression) { }
void IRBuilderVisitor::visit(LiteralFloatExpression* expression) { }
void IRBuilderVisitor::visit(LiteralDoubleExpression* expression) { }
void IRBuilderVisitor::visit(LiteralSymbolExpression* expression) { }
void IRBuilderVisitor::visit(LiteralBoolExpression* expression) { }

void IRBuilderVisitor::visit(LiteralNullExpression *expression) {

}

void IRBuilderVisitor::visit(ListExpression* list) { }
void IRBuilderVisitor::visit(ArrayExpression* array) { }

void IRBuilderVisitor::visit(IdentifierExpression* id) {
    IRInstruction* inst;
    IRValue* dst;
    int kind;

    if (checkingAssignment) {
        kind = id->getSymbol()->getKind();

        switch (kind) {
        case SYMBOL_LOCAL_VARIABLE:
            Variable* var = (Variable*) id->getSymbol()->getDescriptor();
            dst = newTemporary();
            inst = new IRLocalVar(dst, var->getOffset());
            currentFunction->add(inst);
            break;
        }

        //inst = new IRLocalVar()
    }

}
