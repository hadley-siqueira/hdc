#include <iostream>

#include "token/Token.h"
#include "ast/AST.h"
#include "visitors/TACBuilderVisitor.h"
#include "tac/TAC.h"

using namespace hdc;

TACBuilderVisitor::TACBuilderVisitor() {
    tempCounter = 0;
    labelCounter = 0;
    lastTemporary = 0;
    checkingAssignment = false;
    checkingCall = false;
    currentSymtab = nullptr;
}

std::vector<TAC> &TACBuilderVisitor::getTACs() {
    return tacs;
}

int TACBuilderVisitor::newTemporary() {
    lastTemporary = tempCounter;
    tempCounter += 1;

    return lastTemporary;
}

std::string TACBuilderVisitor::newLabel() {
    std::string s = "L";
    s = s + std::to_string(labelCounter);
    labelCounter += 1;
    return s;
}

void TACBuilderVisitor::emit(TACKind kind, int dst, int src1, int src2) {
    TAC tac;

    tac.kind = kind;
    tac.dst = dst;
    tac.src1 = src1;
    tac.src2 = src2;

    tacs.push_back(tac);
}

void TACBuilderVisitor::emit(TACKind kind, int tmp, std::string label) {
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

void TACBuilderVisitor::emit(TACKind kind, int dst) {
    TAC tac;

    tac.kind = kind;
    tac.dst = dst;

    tacs.push_back(tac);
}

void TACBuilderVisitor::emit(TACKind kind, std::string label) {
    TAC tac;

    tac.kind = kind;
    tac.label = label;

    tacs.push_back(tac);
}

void TACBuilderVisitor::emit(TACKind kind) {
    TAC tac;

    tac.kind = kind;
}

void TACBuilderVisitor::visit(SourceFile* file) {
    for (int i = 0; i < file->n_defs(); ++i) {
        file->getDef(i)->accept(this);
    }

    /*for (int i = 0; i < file->n_classes(); ++i) {
        file->getClass(i)->accept(this);
        output << "\n\n";
    }*/
}

void TACBuilderVisitor::visit(Import* import) {

}

void TACBuilderVisitor::visit(Class* klass) {

}

void TACBuilderVisitor::visit(Struct* s) {

}

void TACBuilderVisitor::visit(Def* def) {
    currentSymtab = def->getSymbolTable();

    emit(TAC_LABEL, def->getName());
    def->getStatements()->accept(this);
}

/* Variables */
void TACBuilderVisitor::visit(Parameter* parameter) {

}

void TACBuilderVisitor::visit(Variable* variable) {

}

void TACBuilderVisitor::visit(LocalVariable* variable) {

}

void TACBuilderVisitor::visit(GlobalVariable* variable) {

}

/* Constants */
void TACBuilderVisitor::visit(Constant* c) {

}

void TACBuilderVisitor::visit(GlobalConstant* c) {

}

/* Types */
void TACBuilderVisitor::visit(Type* type) {

}

void TACBuilderVisitor::visit(IntType* type) {

}

void TACBuilderVisitor::visit(UIntType* type) {

}

void TACBuilderVisitor::visit(ShortType* type) {

}

void TACBuilderVisitor::visit(UShortType* type) {

}

void TACBuilderVisitor::visit(LongType* type) {

}

void TACBuilderVisitor::visit(ULongType* type) {

}

void TACBuilderVisitor::visit(CharType* type) {

}

void TACBuilderVisitor::visit(UCharType* type) {

}

void TACBuilderVisitor::visit(FloatType* type) {

}

void TACBuilderVisitor::visit(DoubleType* type) {

}

void TACBuilderVisitor::visit(VoidType* type) {

}

void TACBuilderVisitor::visit(BoolType* type) {

}

void TACBuilderVisitor::visit(SymbolType* type) {

}

void TACBuilderVisitor::visit(Int8Type* type) {

}

void TACBuilderVisitor::visit(Int16Type* type) {

}

void TACBuilderVisitor::visit(Int32Type* type) {

}

void TACBuilderVisitor::visit(Int64Type* type) {

}

void TACBuilderVisitor::visit(UInt8Type* type) {

}

void TACBuilderVisitor::visit(UInt16Type* type) {

}

void TACBuilderVisitor::visit(UInt32Type* type) {

}

void TACBuilderVisitor::visit(UInt64Type* type) {

}

void TACBuilderVisitor::visit(PointerType* type) {

}

void TACBuilderVisitor::visit(NamedType* type) {

}


/* Statements */
void TACBuilderVisitor::visit(Statement* statement) {

}

void TACBuilderVisitor::visit(CompoundStatement* statement) {
    if (statement->n_statements() > 0) {
        int i;

        for (i = 0; i < statement->n_statements(); ++i) {
            statement->getStatement(i)->accept(this);
            emit(TAC_END_EXPR, "");
        }
    }
}

void TACBuilderVisitor::visit(WhileStatement* statement) {
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

void TACBuilderVisitor::visit(ForStatement* statement) {

}

void TACBuilderVisitor::visit(ForEachStatement* statement) {

}

void TACBuilderVisitor::visit(IfStatement* statement) {

}

void TACBuilderVisitor::visit(ElifStatement* statement) {

}

void TACBuilderVisitor::visit(ElseStatement* statement) {

}

void TACBuilderVisitor::visit(ReturnStatement* statement) {
    if (statement->getExpression() != nullptr) {
        statement->getExpression()->accept(this);
        emit(TAC_RETURN_VALUE, lastTemporary, lastTemporary, lastTemporary);
    }

    emit(TAC_RETURN);
}


/* Expressions */
void TACBuilderVisitor::visit(Expression* expression) {

}


/* Unary Expressions */
void TACBuilderVisitor::visit(LogicalNotExpression* expression) {

}

void TACBuilderVisitor::visit(BitwiseNotExpression* expression) {

}

void TACBuilderVisitor::visit(AddressOfExpression* expression) {

}

void TACBuilderVisitor::visit(UnaryMinusExpression* expression) {

}

void TACBuilderVisitor::visit(UnaryPlusExpression* expression) {

}

void TACBuilderVisitor::visit(DolarExpression* expression) {

}

void TACBuilderVisitor::visit(AtExpression* expression) {

}

void TACBuilderVisitor::visit(ParenthesisExpression* expression) {
    expression->getExpression()->accept(this);
}

void TACBuilderVisitor::visit(DereferenceExpression* expression) {

}

void TACBuilderVisitor::visit(PreIncrementExpression* expression) {

}

void TACBuilderVisitor::visit(PreDecrementExpression* expression) {

}

void TACBuilderVisitor::visit(SizeOfExpression* expression) {

}


/* Binary Expresisons */
void TACBuilderVisitor::visit(CallExpression* expression) {
    int tmp;

    for (int i = expression->n_arguments() - 1; i >= 0; --i) {
        expression->getArgument(i)->accept(this);
        emit(TAC_PUSH_PARAM, lastTemporary);
    }

    checkingCall = true;
    expression->getExpression()->accept(this);
    checkingCall = false;
}

void TACBuilderVisitor::visit(DotExpression* expression) {

}

void TACBuilderVisitor::visit(ArrowExpression* expression) {

}

void TACBuilderVisitor::visit(IndexExpression* expression) {

}


void TACBuilderVisitor::visit(ShiftLeftLogicalExpression* expression) {
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

void TACBuilderVisitor::visit(ShiftRightLogicalExpression* expression) {

}

void TACBuilderVisitor::visit(ShiftRightArithmeticExpression* expression) {

}


void TACBuilderVisitor::visit(BitwiseAndExpression* expression) {
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

void TACBuilderVisitor::visit(BitwiseXorExpression* expression) {
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

void TACBuilderVisitor::visit(BitwiseOrExpression* expression) {
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


void TACBuilderVisitor::visit(TimesExpression* expression) {

}

void TACBuilderVisitor::visit(DivisionExpression* expression) {

}

void TACBuilderVisitor::visit(IntegerDivisionExpression* expression) {

}

void TACBuilderVisitor::visit(ModuloExpression* expression) {

}

void TACBuilderVisitor::visit(PlusExpression* expression) {
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

void TACBuilderVisitor::visit(MinusExpression* expression) {
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

void TACBuilderVisitor::visit(LessThanExpression* expression){ }
void TACBuilderVisitor::visit(GreaterThanExpression* expression){ }
void TACBuilderVisitor::visit(LessThanOrEqualExpression* expression){ }
void TACBuilderVisitor::visit(GreaterThanOrEqualExpression* expression){ }
void TACBuilderVisitor::visit(EqualExpression* expression){ }
void TACBuilderVisitor::visit(NotEqualExpression* expression){ }

void TACBuilderVisitor::visit(AssignmentExpression* expression) {
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

void TACBuilderVisitor::visit(BitwiseAndAssignmentExpression* expression) { }
void TACBuilderVisitor::visit(BitwiseXorAssignmentExpression* expression){ }
void TACBuilderVisitor::visit(BitwiseOrAssignmentExpression* expression){ }
void TACBuilderVisitor::visit(BitwiseNotAssignmentExpression* expression){ }
void TACBuilderVisitor::visit(DivisionAssignmentExpression* expression){ }
void TACBuilderVisitor::visit(IntegerDivisionAssignmentExpression* expression){ }
void TACBuilderVisitor::visit(MinusAssignmentExpression* expression){ }
void TACBuilderVisitor::visit(ModuloAssignmentExpression* expression){ }
void TACBuilderVisitor::visit(PlusAssignmentExpression* expression){ }
void TACBuilderVisitor::visit(TimesAssignmentExpression* expression){ }
void TACBuilderVisitor::visit(SllAssignmentExpression* expression){ }
void TACBuilderVisitor::visit(SraAssignmentExpression* expression){ }
void TACBuilderVisitor::visit(SrlAssignmentExpression* expression){ }
void TACBuilderVisitor::visit(SpecialAssignmentExpression* expression){ }

/* Literals */
void TACBuilderVisitor::visit(LiteralIntegerExpression* expression) {
    Token token;

    token = expression->get_token();
    emit(TAC_CONST_I32, newTemporary(), token.getLexem());
}

void TACBuilderVisitor::visit(LiteralStringExpression* expression){ }
void TACBuilderVisitor::visit(LiteralCharExpression* expression){ }
void TACBuilderVisitor::visit(LiteralFloatExpression* expression){ }
void TACBuilderVisitor::visit(LiteralDoubleExpression* expression){ }
void TACBuilderVisitor::visit(LiteralSymbolExpression* expression){ }
void TACBuilderVisitor::visit(LiteralBoolExpression* expression){ }
void TACBuilderVisitor::visit(ListExpression* list){ }
void TACBuilderVisitor::visit(ArrayExpression* array){ }

void TACBuilderVisitor::visit(IdentifierExpression* id) {
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
