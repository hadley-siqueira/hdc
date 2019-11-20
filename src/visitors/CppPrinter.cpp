#include <iostream>
#include "visitors/CppPrinter.h"

using namespace hdc;

CppPrinter::CppPrinter() {
    n_spaces = 0;
}

std::string CppPrinter::print() {
    std::cout << output.str();
    return output.str();
}

void hdc::CppPrinter::visit(SourceFile* file) {
    for (int i = 0; i < file->n_defs(); ++i) {
        file->getDef(i)->accept(this);
    }
}

void CppPrinter::visit(Import* import) {

}

void hdc::CppPrinter::visit(Class* klass) {
    output << "class " << klass->getName();
    output << "{\n";

    indent();

    for (int i = 0; i < klass->n_methods(); ++i) {
        klass->getMethod(i)->accept(this);
    }

    dedent();
    output << "};\n\n";
}

void CppPrinter::visit(Def* def) {
    print_indentation();

    def->getReturnType()->accept(this);
    output << " " << def->getName() << "(";

    for (int i = 0; i < def->n_parameters(); ++i) {
        def->getParameter(i)->accept(this);
    }

    output << ") {\n";
    indent();
    def->getStatements()->accept(this);
    dedent();
    output << "}\n\n";
}

void CppPrinter::visit(Parameter* parameter) {

}

void CppPrinter::visit(Variable* variable) {

}

void CppPrinter::visit(LocalVariable* variable) {

}

/* Types */
void CppPrinter::visit(Type* type) {}

void CppPrinter::visit(IntType* type) {
    output << "int";
}

void CppPrinter::visit(UIntType* type) {
    output << "unsigned int";
}

void CppPrinter::visit(ShortType* type) {
    output << "short";
}

void CppPrinter::visit(UShortType* type) {
    output << "unsigned short";
}

void CppPrinter::visit(LongType* type) {
    output << "long long";
}

void CppPrinter::visit(ULongType* type) {
    output << "unsigned long long";
}

void CppPrinter::visit(CharType* type) {
    output << "char";
}

void CppPrinter::visit(UCharType* type) {
    output << "unsigned char";
}

void CppPrinter::visit(FloatType* type) {
    output << "float";
}

void CppPrinter::visit(DoubleType* type) {
    output << "double";
}

void CppPrinter::visit(VoidType* type) {
    output << "void";
}

void CppPrinter::visit(BoolType* type) {
    output << "bool";
}

void CppPrinter::visit(SymbolType* type) {
    output << "char*";
}

void CppPrinter::visit(Int8Type* type) {
    output << "int8_t";
}

void CppPrinter::visit(Int16Type* type) {
    output << "int16_t";
}

void CppPrinter::visit(Int32Type* type) {
    output << "int32_t";
}

void CppPrinter::visit(Int64Type* type) {
    output << "int64_t";
}

void CppPrinter::visit(UInt8Type* type) {
    output << "uint8_t";
}

void CppPrinter::visit(UInt16Type* type) {
    output << "uint16_t";
}

void CppPrinter::visit(UInt32Type* type) {
    output << "uint32_t";
}

void CppPrinter::visit(UInt64Type* type) {
    output << "uint64_t";
}

void CppPrinter::visit(PointerType* type) {
    type->getSubtype()->accept(this);
    output << "*";
}

/* Statements */
void CppPrinter::visit(Statement* statement) {}

void CppPrinter::visit(CompoundStatement* statement) {
    int i;

    if (statement->n_statements() > 0) {
        for (int i = 0; i < statement->n_statements(); ++i) {
            print_indentation();
            isExpression = false;
            statement->getStatement(i)->accept(this);

            if (isExpression) output << ";";
            output << "\n";
        }

        print_indentation();
        statement->getStatement(i)->accept(this);
        output << "\n";
    }
}

void CppPrinter::visit(WhileStatement* statement) {

}

void CppPrinter::visit(IfStatement* statement) {}
void CppPrinter::visit(ElifStatement* statement) {}
void CppPrinter::visit(ElseStatement* statement) {}

/* Expressions */
void CppPrinter::visit(Expression* expression) {}

/* Unary Expressions */
void CppPrinter::visit(LogicalNotExpression* expression) {

}
void CppPrinter::visit(BitwiseNotExpression* expression) {}
void CppPrinter::visit(AddressOfExpression* expression) {}
void CppPrinter::visit(UnaryMinusExpression* expression) {}
void CppPrinter::visit(UnaryPlusExpression* expression) {}
void CppPrinter::visit(DolarExpression* expression) {}
void CppPrinter::visit(ParenthesisExpression* expression) {}
void CppPrinter::visit(DereferenceExpression* expression) {}
void CppPrinter::visit(PreIncrementExpression* expression) {}
void CppPrinter::visit(PreDecrementExpression* expression) {}
void CppPrinter::visit(SizeOfExpression* expression) {}

/* Binary Expresisons */
void CppPrinter::visit(CallExpression* expression) {}
void CppPrinter::visit(DotExpression* expression) {}
void CppPrinter::visit(ArrowExpression* expression) {}
void CppPrinter::visit(IndexExpression* expression) {}

void CppPrinter::visit(ShiftLeftLogicalExpression* expression) {}
void CppPrinter::visit(ShiftRightLogicalExpression* expression) {}
void CppPrinter::visit(ShiftRightArithmeticExpression* expression) {}

void CppPrinter::visit(BitwiseAndExpression* expression) {}
void CppPrinter::visit(BitwiseXorExpression* expression) {}
void CppPrinter::visit(BitwiseOrExpression* expression) {}

void CppPrinter::visit(TimesExpression* expression) {}
void CppPrinter::visit(DivisionExpression* expression) {}
void CppPrinter::visit(IntegerDivisionExpression* expression) {}
void CppPrinter::visit(ModuloExpression* expression) {}

void CppPrinter::visit(PlusExpression* expression) {}
void CppPrinter::visit(MinusExpression* expression) {}

void CppPrinter::visit(LessThanExpression* expression) {}
void CppPrinter::visit(GreaterThanExpression* expression) {}
void CppPrinter::visit(LessThanOrEqualExpression* expression) {}
void CppPrinter::visit(GreaterThanOrEqualExpression* expression) {}
void CppPrinter::visit(EqualExpression* expression) {}
void CppPrinter::visit(NotEqualExpression* expression) {}

void CppPrinter::visit(AssignmentExpression* expression) {
    isExpression = true;

    expression->getLeft()->accept(this);
    output << " = ";
    expression->getRight()->accept(this);
}

void CppPrinter::visit(BitwiseAndAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " & ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(BitwiseXorAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " ^ ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(BitwiseOrAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " | ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(BitwiseNotAssignmentExpression* expression) {

}

void CppPrinter::visit(DivisionAssignmentExpression* expression) {
    isExpression = true;

    expression->getLeft()->accept(this);
    output << " /= ";
    expression->getRight()->accept(this);
}

void CppPrinter::visit(IntegerDivisionAssignmentExpression* expression) {
    isExpression = true;

    expression->getLeft()->accept(this);
    output << " /= ";
    expression->getRight()->accept(this);
}

void CppPrinter::visit(MinusAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " - ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(ModuloAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " % ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(PlusAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " + ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(TimesAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " * ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(SllAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " << ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(SraAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " >> ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(SrlAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " >> ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(SpecialAssignmentExpression* expression) {}

void CppPrinter::visit(LiteralIntegerExpression* expression) {
    isExpression = true;
    output << expression->get_token().getLexem();
}

void CppPrinter::visit(IdentifierExpression* id) {
    output << id->getName();
}

void CppPrinter::print_indentation() {
    for (int i = 0; i < n_spaces; ++i) {
        output << "    ";
    }
}

void CppPrinter::indent() {
    n_spaces++;
}

void CppPrinter::dedent() {
    n_spaces--;
}
