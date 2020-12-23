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

void PrettyPrinter::visit(Program *program) {

}


void PrettyPrinter::visit(SourceFile* file) {
    output << "Contents of file '";
    output << file->getPath();
    output << "'\n\n";

    for (int i = 0; i < file->n_imports(); ++i) {
        file->getImport(i)->accept(this);
        output << "\n";
    }

    output << "\n";

    if (file->n_global_constants() > 0) {
        for (int i = 0; i < file->n_global_constants(); ++i) {
            file->getGlobalConstant(i)->accept(this);
            output << "\n";
        }

        output << '\n';
    }

    for (int i = 0; i < file->n_global_variables(); ++i) {
        file->getGlobalVariable(i)->accept(this);
        output << "\n";
    }

    output << "\n";

    for (int i = 0; i < file->n_structures(); ++i) {
        file->getStruct(i)->accept(this);
        output << "\n\n";
    }

    for (int i = 0; i < file->n_defs(); ++i) {
        file->getDef(i)->accept(this);
        output << "\n\n";
    }

    for (int i = 0; i < file->n_classes(); ++i) {
        file->getClass(i)->accept(this);
        output << "\n\n";
    }
}


void PrettyPrinter::visit(Import* import) {
    output << import->str();
}

void PrettyPrinter::visit(Class* klass) {
    output << "class " << klass->getName();

    if (klass->hasSuperClass()) {
        output << "(";
        klass->getParentNode()->accept(this);
        output << ")";
    }

    output << ":\n";
    indent();

    for (int i = 0; i < klass->n_methods(); ++i) {
        klass->getMethod(i)->accept(this);
        output << '\n';
    }

    dedent();
}

void PrettyPrinter::visit(Struct* s) {
    output << "struct " << s->getName();

    if (s->hasSuperStruct()) {
        output << "(";
        s->getSuperStruct()->accept(this);
        output << ")";
    }

    output << ":\n";
    indent();

    if (s->n_fields() > 0) {
        for (int i = 0; i < s->n_fields(); ++i) {
            print_indentation();
            output << s->getField(i)->getName();
            output << " : ";
            s->getField(i)->getType()->accept(this);
            output << "\n";
        }
    } else {
        print_indentation();
        output << "pass\n";
    }

    dedent();
}

void PrettyPrinter::visit(Def* def) {
    print_indentation();
    output << "def " << def->getName() << " : ";
    def->getReturnType()->accept(this);
    output << "\n";

    indent();

    if (def->n_parameters() > 0) {
        for (int i = 0; i < def->n_parameters(); ++i) {
            def->getParameter(i)->accept(this);
        }

        output << '\n';
    }

    def->getStatements()->accept(this);
    dedent();
}


void PrettyPrinter::visit(Parameter* parameter) {
    print_indentation();
    output << "@" << parameter->getName() << " : ";
    parameter->getType()->accept(this);
    output << "\n";
}

void PrettyPrinter::visit(Variable* variable) {

}

void PrettyPrinter::visit(LocalVariable* variable) {

}

void PrettyPrinter::visit(GlobalVariable* variable) {
    Type* type;
    Expression* expression;

    if (variable->getIsConstant()) {
        output << "const ";
    } else {
        output << "var ";
    }

    output << variable->getName();

    type = variable->getType();
    expression = variable->getExpression();

    if (type != nullptr) {
        output << " : ";
        type->accept(this);
    }

    if (expression != nullptr) {
        output << " = ";
        expression->accept(this);
    }
}

void PrettyPrinter::visit(ClassVariable *variable) {

}

void PrettyPrinter::visit(Constant* c) {

}

void PrettyPrinter::visit(GlobalConstant* c) {
    output << "const " << c->getName();

    if (c->getType() != nullptr) {
        output << " : ";
        c->getType()->accept(this);
    }

    output << " = ";
    c->getExpression()->accept(this);
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
    type->getSubtype()->accept(this);
    output << "*";
}

void PrettyPrinter::visit(NamedType* type) {
    type->getName()->accept(this);
}

void PrettyPrinter::visit(FunctionType *type) {
    int i;

    for (i = 0; i < type->n_types() - 1; ++i) {
        type->getType(i)->accept(this);
        output << " -> ";
    }

    type->getType(i)->accept(this);
}

/* Statements */
void PrettyPrinter::visit(Statement* statement) {
    output << "UNKNOWN STATEMENT";
}

void PrettyPrinter::visit(class CompoundStatement* statement) {
    if (statement->n_statements() > 0) {
        int i;

        for (i = 0; i < statement->n_statements() - 1; ++i) {
            print_indentation();
            statement->getStatement(i)->accept(this);
            output << '\n';
        }

        print_indentation();
        statement->getStatement(i)->accept(this);
    } else {
        print_indentation();
        output << "pass\n";
    }
}

void PrettyPrinter::visit(WhileStatement* statement) {
    output << "while ";
    statement->getExpression()->accept(this);
    output << ":\n";
    indent();
    statement->getStatements()->accept(this);
    dedent();
}

void PrettyPrinter::visit(ForStatement* statement) {
    output << "for ";

    if (statement->getE1()) {
        statement->getE1()->accept(this);
    }

    output << ";";

    if (statement->getE2()) {
        output << " ";
        statement->getE2()->accept(this);
    }

    output << ";";

    if (statement->getE3()) {
        output << " ";
        statement->getE3()->accept(this);
    }

    output << ":\n";

    indent();
    statement->getStatements()->accept(this);
    dedent();
}

void PrettyPrinter::visit(ForEachStatement* statement) {
    output << "for ";

    statement->getE1()->accept(this);
    output << " in ";
    statement->getE2()->accept(this);
    output << ":\n";
    indent();
    statement->getStatements()->accept(this);
    dedent();
}

void PrettyPrinter::visit(IfStatement* statement) {
    output << "if ";
    statement->getExpression()->accept(this);
    output << ":\n";
    indent();
    statement->getStatements()->accept(this);
    dedent();

    if (statement->getElifStatement()) {
        statement->getElifStatement()->accept(this);
    } else if (statement->getElseStatement()) {
        statement->getElseStatement()->accept(this);
    }
}

void PrettyPrinter::visit(ElifStatement* statement) {
    output << "\n";
    print_indentation();
    output << "elif ";
    statement->getExpression()->accept(this);
    output << ":\n";
    indent();
    statement->getStatements()->accept(this);
    dedent();

    if (statement->getElifStatement()) {
        statement->getElifStatement()->accept(this);
    } else if (statement->getElseStatement()) {
        statement->getElseStatement()->accept(this);
    }
}

void PrettyPrinter::visit(ElseStatement* statement) {
    output << "\n";
    print_indentation();
    output << "else:\n";
    indent();
    statement->getStatements()->accept(this);
    dedent();
}

void PrettyPrinter::visit(ReturnStatement* statement) {
    output << "return";

    if (statement->getExpression()) {
        output << " ";
        statement->getExpression()->accept(this);
    }
}

/* Expressions */
void PrettyPrinter::visit(Expression* expression) {
    output << "UNKNOWN EXPRESSION";
}

/* Unary Expressions */
void PrettyPrinter::visit(LogicalNotExpression* expression) {
    output << "!";
    expression->getExpression()->accept(this);
}

void PrettyPrinter::visit(BitwiseNotExpression* expression) {
    output << "~";
    expression->getExpression()->accept(this);
}

void PrettyPrinter::visit(AddressOfExpression* expression) {
    output << "&";
    expression->getExpression()->accept(this);
}

void PrettyPrinter::visit(UnaryMinusExpression* expression) {
    output << "-";
    expression->getExpression()->accept(this);
}

void PrettyPrinter::visit(UnaryPlusExpression* expression) {
    output << "+";
    expression->getExpression()->accept(this);
}

void PrettyPrinter::visit(DolarExpression* expression) {
    output << "$";
    expression->getExpression()->accept(this);
}

void PrettyPrinter::visit(AtExpression* expression) {
    output << "@";
    expression->getExpression()->accept(this);
}

void PrettyPrinter::visit(ParenthesisExpression* expression) {
    output << "(";
    expression->getExpression()->accept(this);
    output << ")";
}

void PrettyPrinter::visit(DereferenceExpression* expression) {
    output << "*";
    expression->getExpression()->accept(this);
}

void PrettyPrinter::visit(PreIncrementExpression* expression) {
    output << "++";
    expression->getExpression()->accept(this);
}

void PrettyPrinter::visit(PreDecrementExpression* expression) {
    output << "--";
    expression->getExpression()->accept(this);
}

void PrettyPrinter::visit(SizeOfExpression* expression) {
    output << "sizeof(";
    expression->getExpression()->accept(this);
    output << ")";
}

void PrettyPrinter::visit(CallExpression* expression) {
    int i;
    std::vector<Expression*>& arguments = expression->getArguments();

    expression->getExpression()->accept(this);
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

void PrettyPrinter::visit(EqualExpression* expression) {
    expression->getLeft()->accept(this);
    output << " == ";
    expression->getRight()->accept(this);
}

void PrettyPrinter::visit(NotEqualExpression* expression) {
    expression->getLeft()->accept(this);
    output << " != ";
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

void PrettyPrinter::visit(LiteralStringExpression* expression) {
    output << '"' << expression->get_token().getLexem() << '"';
}

void PrettyPrinter::visit(LiteralCharExpression* expression) {
    output << "'" << expression->get_token().getLexem() << "'";
}

void PrettyPrinter::visit(LiteralFloatExpression* expression) {
    output << expression->get_token().getLexem();
}

void PrettyPrinter::visit(LiteralDoubleExpression* expression) {
    output << expression->get_token().getLexem();
}

void PrettyPrinter::visit(LiteralSymbolExpression* expression) {
    output << expression->get_token().getLexem();
}

void PrettyPrinter::visit(LiteralBoolExpression* expression) {
    output << expression->get_token().getLexem();
}

void PrettyPrinter::visit(LiteralNullExpression *expression) {
    output << "null";
}

void PrettyPrinter::visit(ListExpression* list) {
    output << "[";

    if (list->n_expressions() > 0) {
        int i;

        for (i = 0; i < list->n_expressions() - 1; ++i) {
            list->getExpression(i)->accept(this);
            output << ", ";
        }

        list->getExpression(i)->accept(this);
    }

    output << "]";
}

void PrettyPrinter::visit(ArrayExpression* array) {
    output << "{";

    if (array->n_expressions() > 0) {
        int i;

        for (i = 0; i < array->n_expressions() - 1; ++i) {
            array->getExpression(i)->accept(this);
            output << ", ";
        }

        array->getExpression(i)->accept(this);
    }

    output << "}";
}

void PrettyPrinter::visit(IdentifierExpression* id) {
    if (id->hasAlias()) {
        output << id->getAlias();
        output << "::";
    }

    output << id->getName();
}
