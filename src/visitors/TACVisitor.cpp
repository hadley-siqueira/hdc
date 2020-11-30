#include <iostream>

#include "token/Token.h"
#include "ast/AST.h"
#include "visitors/TACVisitor.h"
#include "tac/TAC.h"

using namespace hdc;

TACVisitor::TACVisitor() {
    tempCounter = 0;
    labelCounter = 0;
    lastTemporary = 0;
    checkingAssignment = false;
    checkingCall = false;
    currentSymtab = nullptr;
}

std::vector<TAC> &TACVisitor::getTACs() {
    return tacs;
}

int TACVisitor::newTemporary() {
    lastTemporary = tempCounter;
    tempCounter += 1;

    return lastTemporary;
}

std::string TACVisitor::newLabel() {
    std::string s = "L";
    s = s + std::to_string(labelCounter);
    labelCounter += 1;
    return s;
}

void TACVisitor::emit(TACKind kind, int dst, int src1, int src2) {
    TAC tac;

    tac.kind = kind;
    tac.dst = dst;
    tac.src1 = src1;
    tac.src2 = src2;

    tacs.push_back(tac);
}

void TACVisitor::emit(TACKind kind, int tmp, std::string label) {
    TAC tac;

    tac.kind = kind;

    // we set src1 = src2 = dst = tmp because sometimes this emit will call a copy instruction or similar
    // and other times it is gonna be called as a conditional jump

    if (kind == TAC_IFZ)
        tac.src1 = tmp;
    tac.dst = tmp;
    tac.label = label;

    tacs.push_back(tac);
}

void TACVisitor::emit(TACKind kind, int dst) {
    TAC tac;

    tac.kind = kind;
    tac.dst = dst;

    tacs.push_back(tac);
}

void TACVisitor::emit(TACKind kind, std::string label) {
    TAC tac;

    tac.kind = kind;
    tac.label = label;

    tacs.push_back(tac);
}

void TACVisitor::emit(TACKind kind) {
    TAC tac;

    tac.kind = kind;
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
    currentSymtab = def->getSymbolTable();

    emit(TAC_LABEL, def->getName());
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
    if (statement->n_statements() > 0) {
        int i;

        for (i = 0; i < statement->n_statements(); ++i) {
            statement->getStatement(i)->accept(this);
            emit(TAC_END_EXPR, "");
        }
    }
}

void TACVisitor::visit(WhileStatement* statement) {
    std::string labelBefore;
    std::string labelAfter;

    labelBefore = newLabel();
    labelAfter = newLabel();

    emit(TAC_LABEL, labelBefore);
    statement->getExpression()->accept(this);
    emit(TAC_IFZ, lastTemporary, labelAfter);
    emit(TAC_END_EXPR, "");

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
    if (statement->getExpression() != nullptr) {
        statement->getExpression()->accept(this);
        emit(TAC_RETURN_VALUE, lastTemporary, lastTemporary, lastTemporary);
    }

    emit(TAC_RETURN);
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
    expression->getExpression()->accept(this);
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
    int tmp;

    for (int i = expression->n_arguments() - 1; i >= 0; --i) {
        expression->getArgument(i)->accept(this);
        emit(TAC_PUSH_PARAM, lastTemporary);
    }

    checkingCall = true;
    expression->getExpression()->accept(this);
    checkingCall = false;
}

void TACVisitor::visit(DotExpression* expression) {

}

void TACVisitor::visit(ArrowExpression* expression) {

}

void TACVisitor::visit(IndexExpression* expression) {

}


void TACVisitor::visit(ShiftLeftLogicalExpression* expression) {
    int src1;
    int src2;
    int dst;

    expression->getLeft()->accept(this);
    src1 = lastTemporary;

    expression->getRight()->accept(this);
    src2 = lastTemporary;

    dst = newTemporary();
    emit(TAC_SLL, dst, src1, src2);
}

void TACVisitor::visit(ShiftRightLogicalExpression* expression) {

}

void TACVisitor::visit(ShiftRightArithmeticExpression* expression) {

}


void TACVisitor::visit(BitwiseAndExpression* expression) {
    int src1;
    int src2;
    int dst;

    expression->getLeft()->accept(this);
    src1 = lastTemporary;

    expression->getRight()->accept(this);
    src2 = lastTemporary;

    dst = newTemporary();
    emit(TAC_BITWISE_AND, dst, src1, src2);
}

void TACVisitor::visit(BitwiseXorExpression* expression) {
    int src1;
    int src2;
    int dst;

    expression->getLeft()->accept(this);
    src1 = lastTemporary;

    expression->getRight()->accept(this);
    src2 = lastTemporary;

    dst = newTemporary();
    emit(TAC_BITWISE_XOR, dst, src1, src2);
}

void TACVisitor::visit(BitwiseOrExpression* expression) {
    int src1;
    int src2;
    int dst;

    expression->getLeft()->accept(this);
    src1 = lastTemporary;

    expression->getRight()->accept(this);
    src2 = lastTemporary;

    dst = newTemporary();
    emit(TAC_BITWISE_OR, dst, src1, src2);
}


void TACVisitor::visit(TimesExpression* expression) {

}

void TACVisitor::visit(DivisionExpression* expression) {

}

void TACVisitor::visit(IntegerDivisionExpression* expression) {

}

void TACVisitor::visit(ModuloExpression* expression) {

}

void TACVisitor::visit(PlusExpression* expression) {
    int src1;
    int src2;
    int dst;

    expression->getLeft()->accept(this);
    src1 = lastTemporary;

    expression->getRight()->accept(this);
    src2 = lastTemporary;

    dst = newTemporary();
    emit(TAC_ADD, dst, src1, src2);
}

void TACVisitor::visit(MinusExpression* expression) {
    int src1;
    int src2;
    int dst;

    expression->getLeft()->accept(this);
    src1 = lastTemporary;

    expression->getRight()->accept(this);
    src2 = lastTemporary;

    dst = newTemporary();
    emit(TAC_SUB, dst, src1, src2);
}

void TACVisitor::visit(LessThanExpression* expression){ }
void TACVisitor::visit(GreaterThanExpression* expression){ }
void TACVisitor::visit(LessThanOrEqualExpression* expression){ }
void TACVisitor::visit(GreaterThanOrEqualExpression* expression){ }
void TACVisitor::visit(EqualExpression* expression){ }
void TACVisitor::visit(NotEqualExpression* expression){ }

void TACVisitor::visit(AssignmentExpression* expression) {
    int tmp1 = -1;
    int tmp2 = -1;
    int dst = -1;
    bool oldCheckingAssignment;

    oldCheckingAssignment = checkingAssignment;

    checkingAssignment = false;
    expression->getRight()->accept(this);
    tmp1 = lastTemporary;

    checkingAssignment = true;
    expression->getLeft()->accept(this);
    dst = lastTemporary;
    tmp2 = dst;

    emit(TAC_SW, dst, tmp1, tmp2);
    checkingAssignment = oldCheckingAssignment;
}

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

    token = expression->get_token();
    emit(TAC_CONST_I32, newTemporary(), token.getLexem());
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
    int tmp;

    if (checkingAssignment) {
        emit(TAC_GET_VAR, newTemporary(), id->getName());
    } else {
        if (checkingCall) {
            //currentSymtab->has(id->getName());
            emit(TAC_LCALL, newTemporary(), id->getName());
        } else {
            emit(TAC_GET_VAR, newTemporary(), id->getName());
            tmp = lastTemporary;

            emit(TAC_LW, newTemporary(), tmp, tmp);
        }
    }
}
