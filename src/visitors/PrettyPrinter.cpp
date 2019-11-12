#include <iostream>

#include "ast/AST.h"
#include "visitors/PrettyPrinter.h"

using namespace hdc;

PrettyPrinter::PrettyPrinter() {
    n_spaces = 0;
}


void PrettyPrinter::print_indentation() {
    for (int i = 0; i < n_spaces; ++i) {
        output << "    ";
    }
}


void PrettyPrinter::indent() {
    n_spaces++;
}


void PrettyPrinter::dedent() {
    n_spaces--;
}


void PrettyPrinter::print() {
    std::cout << output.str();
}


void PrettyPrinter::visit(SourceFile* file) {
    output << "Contents of file '";
    output << file->get_path();
    output << "'\n\n";

    for (int i = 0; i < file->n_imports(); ++i) {
        file->get_import(i)->accept(this);
        output << "\n";
    }

    output << "\n";

    for (int i = 0; i < file->n_defs(); ++i) {
        file->get_def(i)->accept(this);
        output << "\n\n";
    }

    for (int i = 0; i < file->n_classes(); ++i) {
        file->get_class(i)->accept(this);
        output << "\n\n";
    }
}


void PrettyPrinter::visit(Import* import) {
    output << import->str();
}

void PrettyPrinter::visit(Class* klass) {
    output << "class " << klass->get_name();

    if (klass->has_parent()) {
        output << "(";
        klass->get_parent()->accept(this);
        output << ")";
    }

    output << ":\n";
    indent();

    for (int i = 0; i < klass->n_methods(); ++i) {
        klass->get_method(i)->accept(this);
        output << '\n';
    }

    dedent();
}

void PrettyPrinter::visit(Def* def) {
    print_indentation();
    output << "def " << def->get_name() << " : ";
    def->get_return_type()->accept(this);
    output << "\n";

    indent();

    for (int i = 0; i < def->n_parameters(); ++i) {
        def->get_parameter(i)->accept(this);
    }

    output << '\n';
    def->get_statements()->accept(this);
    dedent();
}


void PrettyPrinter::visit(Parameter* parameter) {
    print_indentation();
    output << "@" << parameter->get_name() << " : ";
    parameter->get_type()->accept(this);
    output << "\n";
}


void PrettyPrinter::visit(Type* type) {
    output << "UNKNOWN TYPE";
}

void PrettyPrinter::visit(IntType* type) {
    output << "int";
}

void PrettyPrinter::visit(class UIntType* type) {
    output << "uint";
}

void PrettyPrinter::visit(class ShortType* type) {
    output << "short";
}

void PrettyPrinter::visit(class UShortType* type) {
    output << "ushort";
}

void PrettyPrinter::visit(class LongType* type) {
    output << "long";
}

void PrettyPrinter::visit(class ULongType* type) {
    output << "ulong";
}

void PrettyPrinter::visit(class CharType* type) {
    output << "char";
}

void PrettyPrinter::visit(class UCharType* type) {
    output << "uchar";
}

void PrettyPrinter::visit(class FloatType* type) {
    output << "float";
}

void PrettyPrinter::visit(class DoubleType* type) {
    output << "double";
}

void PrettyPrinter::visit(class VoidType* type) {
    output << "void";
}

void PrettyPrinter::visit(class BoolType* type) {
    output << "bool";
}

void PrettyPrinter::visit(class SymbolType* type) {
    output << "symbol";
}

void PrettyPrinter::visit(class Int8Type* type) {
    output << "i8";
}

void PrettyPrinter::visit(class Int16Type* type) {
    output << "i16";
}

void PrettyPrinter::visit(class Int32Type* type) {
    output << "i32";
}

void PrettyPrinter::visit(class Int64Type* type) {
    output << "i64";
}

void PrettyPrinter::visit(class UInt8Type* type) {
    output << "u8";
}

void PrettyPrinter::visit(class UInt16Type* type) {
    output << "u16";
}

void PrettyPrinter::visit(class UInt32Type* type) {
    output << "u32";
}

void PrettyPrinter::visit(class UInt64Type* type) {
    output << "u64";
}

void PrettyPrinter::visit(PointerType* type) {
    type->get_subtype()->accept(this);
    output << "*";
}

/* Statements */
void PrettyPrinter::visit(Statement* statement) {
    output << "UNKNOWN STATEMENT";
}

void PrettyPrinter::visit(class CompoundStatement* statement) {
    if (statement->n_statements() > 0) {
        for (int i = 0; i < statement->n_statements(); ++i) {
            print_indentation();
            statement->get_statement(i)->accept(this);
            output << '\n';
        }
    } else {
        print_indentation();
        output << "pass\n";
    }
}

void PrettyPrinter::visit(WhileStatement* statement) {
    output << "while ";
    statement->get_expression()->accept(this);
    output << ":\n";
    indent();
    statement->get_statements()->accept(this);
    dedent();
}

/* Expressions */
void PrettyPrinter::visit(Expression* expression) {
    output << "UNKNOWN EXPRESSION";
}

/* Unary Expressions */
void PrettyPrinter::visit(LogicalNotExpression* expression) {
    output << "!";
    expression->get_expression()->accept(this);
}

void PrettyPrinter::visit(BitwiseNotExpression* expression) {
    output << "~";
    expression->get_expression()->accept(this);
}

void PrettyPrinter::visit(AddressOfExpression* expression) {
    output << "&";
    expression->get_expression()->accept(this);
}

void PrettyPrinter::visit(UnaryMinusExpression* expression) {
    output << "-";
    expression->get_expression()->accept(this);
}

void PrettyPrinter::visit(UnaryPlusExpression* expression) {
    output << "+";
    expression->get_expression()->accept(this);
}

void PrettyPrinter::visit(DolarExpression* expression) {
    output << "$";
    expression->get_expression()->accept(this);
}

void PrettyPrinter::visit(ParenthesisExpression* expression) {
    output << "(";
    expression->get_expression()->accept(this);
    output << ")";
}

void PrettyPrinter::visit(DereferenceExpression* expression) {
    output << "*";
    expression->get_expression()->accept(this);
}

void PrettyPrinter::visit(PreIncrementExpression* expression) {
    output << "++";
    expression->get_expression()->accept(this);
}

void PrettyPrinter::visit(PreDecrementExpression* expression) {
    output << "--";
    expression->get_expression()->accept(this);
}

void PrettyPrinter::visit(SizeOfExpression* expression) {
    output << "sizeof(";
    expression->get_expression()->accept(this);
    output << ")";
}

void PrettyPrinter::visit(CallExpression* expression) {
    int i;
    std::vector<Expression*>& arguments = expression->get_arguments();

    expression->get_expression()->accept(this);
    output << "(";

    if (arguments.size() > 0) {
        for (i = 0; i < arguments.size() - 1; ++i) {
            arguments[i]->accept(this);
            output << ", ";
        }

        arguments[i]->accept(this);
    }

    output << ")";
}

void PrettyPrinter::visit(DotExpression* expression) {
    expression->getLeft()->accept(this);
    output << ".";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(ArrowExpression* expression) {
    expression->getLeft()->accept(this);
    output << "->";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(IndexExpression* expression) {
    expression->getLeft()->accept(this);
    output << "[";
    expression->getRight()->accept(this);
    output << "]";
}

/* Shift */
void PrettyPrinter::visit(ShiftLeftLogicalExpression* expression) {
    expression->getLeft()->accept(this);
    output << " << ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(ShiftRightLogicalExpression* expression) {
    expression->getLeft()->accept(this);
    output << " >>> ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(ShiftRightArithmeticExpression* expression) {
    expression->getLeft()->accept(this);
    output << " >> ";
    expression->getRight()->accept(this);
}

/* Bitwise */
void PrettyPrinter::visit(BitwiseAndExpression* expression) {
    expression->getLeft()->accept(this);
    output << " & ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(BitwiseXorExpression* expression) {
    expression->getLeft()->accept(this);
    output << " ^ ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(BitwiseOrExpression* expression) {
    expression->getLeft()->accept(this);
    output << " | ";
    expression->getRight()->accept(this);
}

/* Term */
void PrettyPrinter::visit(TimesExpression* expression) {
    expression->getLeft()->accept(this);
    output << " * ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(DivisionExpression* expression) {
    expression->getLeft()->accept(this);
    output << " / ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(IntegerDivisionExpression* expression) {
    expression->getLeft()->accept(this);
    output << " // ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(ModuloExpression* expression) {
    expression->getLeft()->accept(this);
    output << " % ";
    expression->getRight()->accept(this);
}

/* Arith */
void PrettyPrinter::visit(PlusExpression* expression) {
    expression->getLeft()->accept(this);
    output << " + ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(MinusExpression* expression) {
    expression->getLeft()->accept(this);
    output << " - ";
    expression->getRight()->accept(this);
}

/* Relational */
void PrettyPrinter::visit(LessThanExpression* expression) {
    expression->getLeft()->accept(this);
    output << " < ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(GreaterThanExpression* expression) {
    expression->getLeft()->accept(this);
    output << " > ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(LessThanOrEqualExpression* expression) {
    expression->getLeft()->accept(this);
    output << " <= ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(GreaterThanOrEqualExpression* expression) {
    expression->getLeft()->accept(this);
    output << " >= ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(AssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    output << " = ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(BitwiseAndAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    output << " &= ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(BitwiseXorAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    output << " ^= ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(BitwiseOrAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    output << " |= ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(BitwiseNotAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    output << " ~= ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(DivisionAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    output << " /= ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(IntegerDivisionAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    output << " //= ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(MinusAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    output << " -= ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(ModuloAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    output << " %= ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(PlusAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    output << " += ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(TimesAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    output << " *= ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(SllAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    output << " <<= ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(SraAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    output << " >>= ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(SrlAssignmentExpression* expression) {
    expression->getLeft()->accept(this);
    output << " >>>= ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(SpecialAssignmentExpression* expression) { 
    expression->getLeft()->accept(this);
    output << " := ";
    expression->getRight()->accept(this);
}

/* Literals */
void PrettyPrinter::visit(LiteralIntegerExpression* expression) {
    output << expression->get_token().getLexem();
}

void PrettyPrinter::visit(IdentifierExpression* id) {
    if (id->has_alias()) {
        output << id->get_alias();
        output << "::";
    }

    output << id->get_name();
}
