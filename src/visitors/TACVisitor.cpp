#include "token/Token.h"
#include "ast/AST.h"
#include "visitors/TACVisitor.h"
#include "tac/TAC.h"

using namespace hdc;

TACVisitor::TACVisitor() {
    tempCounter = 0;
    labelCounter = 0;
    lastTemporary = 0;
}

int TACVisitor::newTemporary() {
    lastTemporary = tempCounter;
    tempCounter += 1;

    return lastTemporary;
}

std::string TACVisitor::newLabel() {
    std::string s = "L";
    s = s + std::to_string(labelCounter);
    return s;
}

void TACVisitor::emit(TACKind kind, int tmp, std::string label) {
    TAC tac;

    tac.kind = kind;

    // we set src1 = src2 = dst = tmp because sometimes this emit will call a copy instruction or similar
    // and other times it is gonna be called as a conditional jump
    tac.src1 = tmp;
    tac.src2 = tmp;
    tac.dst = tmp;

    tac.label = label;

    tacs.push_back(tac);
}

void TACVisitor::emit(TACKind kind, std::string label) {
    TAC tac;

    tac.kind = kind;
    tac.label = label;

    tacs.push_back(tac);
}

void TACVisitor::visit(SourceFile* file) {
    for (int i = 0; i < file->n_defs(); ++i) {
        file->getDef(i)->accept(this);
    }

    /*for (int i = 0; i < file->n_classes(); ++i) {
        file->getClass(i)->accept(this);
        output << "\n\n";
    }*/
}

void TACVisitor::visit(Import* import) {

}

void TACVisitor::visit(Class* klass) {

}

void TACVisitor::visit(Struct* s) {

}

void TACVisitor::visit(Def* def) {
    def->getStatements()->accept(this);
}

/* Variables */
void TACVisitor::visit(Parameter* parameter) {

}

void TACVisitor::visit(Variable* variable) {

}

void TACVisitor::visit(LocalVariable* variable) {

}

void TACVisitor::visit(GlobalVariable* variable) {

}

/* Constants */
void TACVisitor::visit(Constant* c) {

}

void TACVisitor::visit(GlobalConstant* c) {

}

/* Types */
void TACVisitor::visit(Type* type) {

}

void TACVisitor::visit(IntType* type) {

}

void TACVisitor::visit(UIntType* type) {

}

void TACVisitor::visit(ShortType* type) {

}

void TACVisitor::visit(UShortType* type) {

}

void TACVisitor::visit(LongType* type) {

}

void TACVisitor::visit(ULongType* type) {

}

void TACVisitor::visit(CharType* type) {

}

void TACVisitor::visit(UCharType* type) {

}

void TACVisitor::visit(FloatType* type) {

}

void TACVisitor::visit(DoubleType* type) {

}

void TACVisitor::visit(VoidType* type) {

}

void TACVisitor::visit(BoolType* type) {

}

void TACVisitor::visit(SymbolType* type) {

}

void TACVisitor::visit(Int8Type* type) {

}

void TACVisitor::visit(Int16Type* type) {

}

void TACVisitor::visit(Int32Type* type) {

}

void TACVisitor::visit(Int64Type* type) {

}

void TACVisitor::visit(UInt8Type* type) {

}

void TACVisitor::visit(UInt16Type* type) {

}

void TACVisitor::visit(UInt32Type* type) {

}

void TACVisitor::visit(UInt64Type* type) {

}

void TACVisitor::visit(PointerType* type) {

}

void TACVisitor::visit(NamedType* type) {

}


/* Statements */
void TACVisitor::visit(Statement* statement) {

}

void TACVisitor::visit(CompoundStatement* statement) {

}

void TACVisitor::visit(WhileStatement* statement) {
    std::string labelBefore;
    std::string labelAfter;

    labelBefore = newLabel();
    labelAfter = newLabel();

    emit(TAC_LABEL, labelBefore);
    statement->getExpression()->accept(this);

    emit(TAC_IFZ, lastTemporary, labelAfter);
    statement->getStatements()->accept(this);

    emit(TAC_GOTO, labelBefore);
    emit(TAC_LABEL, labelAfter);
}

void TACVisitor::visit(ForStatement* statement) {

}

void TACVisitor::visit(ForEachStatement* statement) {

}

void TACVisitor::visit(IfStatement* statement) {

}

void TACVisitor::visit(ElifStatement* statement) {

}

void TACVisitor::visit(ElseStatement* statement) {

}

void TACVisitor::visit(ReturnStatement* statement) {

}


/* Expressions */
void TACVisitor::visit(Expression* expression) {

}


/* Unary Expressions */
void TACVisitor::visit(LogicalNotExpression* expression) {

}

void TACVisitor::visit(BitwiseNotExpression* expression) {

}

void TACVisitor::visit(AddressOfExpression* expression) {

}

void TACVisitor::visit(UnaryMinusExpression* expression) {

}

void TACVisitor::visit(UnaryPlusExpression* expression) {

}

void TACVisitor::visit(DolarExpression* expression) {

}

void TACVisitor::visit(AtExpression* expression) {

}

void TACVisitor::visit(ParenthesisExpression* expression) {

}

void TACVisitor::visit(DereferenceExpression* expression) {

}

void TACVisitor::visit(PreIncrementExpression* expression) {

}

void TACVisitor::visit(PreDecrementExpression* expression) {

}

void TACVisitor::visit(SizeOfExpression* expression) {

}


/* Binary Expresisons */
void TACVisitor::visit(CallExpression* expression) {

}

void TACVisitor::visit(DotExpression* expression) {

}

void TACVisitor::visit(ArrowExpression* expression) {

}

void TACVisitor::visit(IndexExpression* expression) {

}


void TACVisitor::visit(ShiftLeftLogicalExpression* expression) {

}

void TACVisitor::visit(ShiftRightLogicalExpression* expression) {

}

void TACVisitor::visit(ShiftRightArithmeticExpression* expression) {

}


void TACVisitor::visit(BitwiseAndExpression* expression) {

}

void TACVisitor::visit(BitwiseXorExpression* expression) {

}

void TACVisitor::visit(BitwiseOrExpression* expression) {

}


void TACVisitor::visit(TimesExpression* expression) {

}

void TACVisitor::visit(DivisionExpression* expression) {

}

void TACVisitor::visit(IntegerDivisionExpression* expression) {

}

void TACVisitor::visit(ModuloExpression* expression) {

}


void TACVisitor::visit(PlusExpression* expression){ }
void TACVisitor::visit(MinusExpression* expression){ }

void TACVisitor::visit(LessThanExpression* expression){ }
void TACVisitor::visit(GreaterThanExpression* expression){ }
void TACVisitor::visit(LessThanOrEqualExpression* expression){ }
void TACVisitor::visit(GreaterThanOrEqualExpression* expression){ }
void TACVisitor::visit(EqualExpression* expression){ }
void TACVisitor::visit(NotEqualExpression* expression){ }

void TACVisitor::visit(AssignmentExpression* expression){ }
void TACVisitor::visit(BitwiseAndAssignmentExpression* expression){ }
void TACVisitor::visit(BitwiseXorAssignmentExpression* expression){ }
void TACVisitor::visit(BitwiseOrAssignmentExpression* expression){ }
void TACVisitor::visit(BitwiseNotAssignmentExpression* expression){ }
void TACVisitor::visit(DivisionAssignmentExpression* expression){ }
void TACVisitor::visit(IntegerDivisionAssignmentExpression* expression){ }
void TACVisitor::visit(MinusAssignmentExpression* expression){ }
void TACVisitor::visit(ModuloAssignmentExpression* expression){ }
void TACVisitor::visit(PlusAssignmentExpression* expression){ }
void TACVisitor::visit(TimesAssignmentExpression* expression){ }
void TACVisitor::visit(SllAssignmentExpression* expression){ }
void TACVisitor::visit(SraAssignmentExpression* expression){ }
void TACVisitor::visit(SrlAssignmentExpression* expression){ }
void TACVisitor::visit(SpecialAssignmentExpression* expression){ }

/* Literals */
void TACVisitor::visit(LiteralIntegerExpression* expression) {
    Token token;
    TAC tac;

    token = expression->get_token();

    tac.kind = TAC_CONST_I32;
    tac.dst = newTemporary();
    tac.label = token.getLexem();
}

void TACVisitor::visit(LiteralStringExpression* expression){ }
void TACVisitor::visit(LiteralCharExpression* expression){ }
void TACVisitor::visit(LiteralFloatExpression* expression){ }
void TACVisitor::visit(LiteralDoubleExpression* expression){ }
void TACVisitor::visit(LiteralSymbolExpression* expression){ }
void TACVisitor::visit(LiteralBoolExpression* expression){ }
void TACVisitor::visit(ListExpression* list){ }
void TACVisitor::visit(ArrayExpression* array){ }

void TACVisitor::visit(IdentifierExpression* id) {

}
