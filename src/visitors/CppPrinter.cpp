#include <iostream>
#include <fstream>
#include "visitors/CppPrinter.h"

using namespace hdc;

CppPrinter::CppPrinter() {
    n_spaces = 0;
    printStart();
}

std::string CppPrinter::print() {
    std::cout << output.str();
    return output.str();
}

void CppPrinter::save(std::string path) {
    std::ofstream file;

    file.open(path);
    file << output.str();
    file.close();
}

void hdc::CppPrinter::visit(SourceFile* file) {
    generatePrototypes(file);

    for (int i = 0; i < file->n_classes(); ++i) {
        file->getClass(i)->accept(this);
    }

    for (int i = 0; i < file->n_defs(); ++i) {
        file->getDef(i)->accept(this);
    }

    printEnd();
}

void CppPrinter::visit(Import* import) {

}

void hdc::CppPrinter::visit(Class* klass) {
    output << "class " << klass->getUniqueCppName();
    output << " {\npublic:\n";

    indent();

    for (int i = 0; i < klass->n_methods(); ++i) {
        klass->getMethod(i)->accept(this);
    }

    output << '\n';

    for (int i = 0; i < klass->n_variables(); ++i) {
        print_indentation();
        klass->getVariable(i)->getType()->accept(this);
        output << " " << klass->getVariable(i)->getUniqueCppName() << ";\n";
    }

    dedent();
    output << "};\n\n";
}

void CppPrinter::visit(Struct* s) {

}

void CppPrinter::visit(Def* def) {
    print_indentation();
    def->getReturnType()->accept(this);
    output << " " << def->getUniqueCppName() << "(";

    generateDefParameters(def);
    output << ") {\n";

    indent();

    generateDefLocalVariables(def);
    output << "\n";

    def->getStatements()->accept(this);
    dedent();
    print_indentation();
    output << "}\n\n";

    if (def->getName().compare("main") == 0 && def->getClass() == nullptr) {
        mainDef = def;
    }
}

void CppPrinter::visit(Parameter* parameter) {
    if (parameter->getType()) {
        parameter->getType()->accept(this);
    } else {
        output << "int";
    }

    output << " p" << parameter->getLocalName() << "_" << parameter->getName();
}

void CppPrinter::visit(Variable* variable) {

}

void CppPrinter::visit(LocalVariable* variable) {
    print_indentation();

    if (variable->getType()) {
        variable->getType()->accept(this);
    } else {
        output << "int";
    }

    output << " lv" << variable->getLocalName() << "_";
    output << variable->getName() << ";\n";
}

void CppPrinter::visit(GlobalVariable* variable) {

}

void CppPrinter::visit(Constant* c) {

}

void CppPrinter::visit(GlobalConstant* c) {

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

void CppPrinter::visit(NamedType* type) {
    type->getName()->accept(this);
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
    }
}

void CppPrinter::visit(WhileStatement* statement) {
    output << "while (";
    statement->getExpression()->accept(this);
    output << ") {\n";

    indent();
    statement->getStatements()->accept(this);
    dedent();
    print_indentation();
    output << "}\n";
    isExpression = false;
}

void CppPrinter::visit(ForStatement* statement) {

}

void CppPrinter::visit(ForEachStatement* statement) {

}

void CppPrinter::visit(IfStatement* statement) {
    output << "if (";
    statement->getExpression()->accept(this);
    output << ") {\n";

    indent();
    statement->getStatements()->accept(this);
    dedent();

    print_indentation();
    output << "}";

    if (statement->getElifStatement()) {
        statement->getElifStatement()->accept(this);
    } else if (statement->getElseStatement()) {
        statement->getElseStatement()->accept(this);
    }

    isExpression = false;
}

void CppPrinter::visit(ElifStatement* statement) {
    output << " else if (";
    statement->getExpression()->accept(this);
    output << ") {\n";

    indent();
    statement->getStatements()->accept(this);
    dedent();

    print_indentation();
    output << "}";

    if (statement->getElifStatement()) {
        statement->getElifStatement()->accept(this);
    } else if (statement->getElseStatement()) {
        statement->getElseStatement()->accept(this);
    }
}

void CppPrinter::visit(ElseStatement* statement) {
    output << " else {\n";
    indent();
    statement->getStatements()->accept(this);
    dedent();

    print_indentation();
    output << "}";
}

void CppPrinter::visit(ReturnStatement* statement) {
    output << "return";

    if (statement->getExpression()) {
        output << " ";
        statement->getExpression()->accept(this);
    }
}

/* Expressions */
void CppPrinter::visit(Expression* expression) {}

/* Unary Expressions */
void CppPrinter::visit(LogicalNotExpression* expression) {
    isExpression = true;

    output << "!";
    expression->getExpression()->accept(this);
}

void CppPrinter::visit(BitwiseNotExpression* expression) {
    isExpression = true;

    output << "~";
    expression->getExpression()->accept(this);
}

void CppPrinter::visit(AddressOfExpression* expression) {
    isExpression = true;

    output << "&";
    expression->getExpression()->accept(this);
}

void CppPrinter::visit(UnaryMinusExpression* expression) {
    isExpression = true;

    output << "-";
    expression->getExpression()->accept(this);
}

void CppPrinter::visit(UnaryPlusExpression* expression) {
    isExpression = true;

    output << "+";
    expression->getExpression()->accept(this);
}

void CppPrinter::visit(DolarExpression* expression) {
    isExpression = true;
    LiteralStringExpression* str;

    str = (LiteralStringExpression*) expression->getExpression();
    output << str->get_token().getLexem();
}

void CppPrinter::visit(AtExpression* expression) {
    isExpression = true;

    output << "this->";
    expression->getExpression()->accept(this);
}

void CppPrinter::visit(ParenthesisExpression* expression) {
    output << "(";
    expression->getExpression()->accept(this);
    output << ")";
}

void CppPrinter::visit(DereferenceExpression* expression) {
    isExpression = true;

    output << "*";
    expression->getExpression()->accept(this);
}

void CppPrinter::visit(PreIncrementExpression* expression) {
    isExpression = true;

    output << "++";
    expression->getExpression()->accept(this);
}

void CppPrinter::visit(PreDecrementExpression* expression) {
    isExpression = true;

    output << "--";
    expression->getExpression()->accept(this);
}

void CppPrinter::visit(SizeOfExpression* expression) {
    isExpression = true;

    output << "sizeof(";
    expression->getExpression()->accept(this);
    output << ")";
}

/* Binary Expresisons */
void CppPrinter::visit(CallExpression* expression) {
    int i = 0;

    isExpression = true;
    expression->getExpression()->accept(this);

    output << "(";

    if (expression->n_arguments() > 0) {
        for (i = 0; i < expression->n_arguments() - 1; ++i) {
            expression->getArgument(i)->accept(this);
            output << ", ";
        }

        expression->getArgument(i)->accept(this);
    }

    output << ")";
}

void CppPrinter::visit(DotExpression* expression) {
    isExpression = true;

    expression->getLeft()->accept(this);
    output << ".";
    expression->getRight()->accept(this);
}

void CppPrinter::visit(ArrowExpression* expression) {
    isExpression = true;

    expression->getLeft()->accept(this);
    output << "->";
    expression->getRight()->accept(this);
}

void CppPrinter::visit(IndexExpression* expression) {
    isExpression = true;

    expression->getLeft()->accept(this);
    output << "[";
    expression->getRight()->accept(this);
    output << "]";
}

void CppPrinter::visit(ShiftLeftLogicalExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " << ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(ShiftRightLogicalExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " >> ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(ShiftRightArithmeticExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " >> ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(BitwiseAndExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " & ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(BitwiseXorExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " ^ ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(BitwiseOrExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " | ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(TimesExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " * ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(DivisionExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " / ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(IntegerDivisionExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " / ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(ModuloExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " % ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(PlusExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " + ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(MinusExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " - ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(LessThanExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " < ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(GreaterThanExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " > ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(LessThanOrEqualExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " <= ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(GreaterThanOrEqualExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " >= ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(EqualExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " == ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(NotEqualExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " != ";
    expression->getRight()->accept(this);
    output << ")";
}

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
    output << " &= ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(BitwiseXorAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " ^= ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(BitwiseOrAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " |= ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(BitwiseNotAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " ~= ";
    expression->getRight()->accept(this);
    output << ")";
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
    output << " -= ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(ModuloAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " %= ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(PlusAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " += ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(TimesAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " *= ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(SllAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " <<= ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(SraAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " >>= ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(SrlAssignmentExpression* expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " >>= ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(SpecialAssignmentExpression* expression) {}

void CppPrinter::visit(LiteralIntegerExpression* expression) {
    isExpression = true;
    output << expression->get_token().getLexem();
}

void CppPrinter::visit(LiteralStringExpression* expression) {
    isExpression = true;
    output << '"' << expression->get_token().getLexem() << '"';
}

void CppPrinter::visit(LiteralCharExpression* expression) {
    isExpression = true;
    output << "'" << expression->get_token().getLexem() << "'";
}

void CppPrinter::visit(LiteralFloatExpression* expression) {
    isExpression = true;
    output << expression->get_token().getLexem();
}

void CppPrinter::visit(LiteralDoubleExpression* expression) {
    isExpression = true;
    output << expression->get_token().getLexem();
}

void CppPrinter::visit(LiteralSymbolExpression* expression) {
    isExpression = true;
    output << '"' << expression->get_token().getLexem() << '"';
}

void CppPrinter::visit(LiteralBoolExpression* expression) {
    isExpression = true;
    output << expression->get_token().getLexem();
}

void CppPrinter::visit(ListExpression* list) {

}

void CppPrinter::visit(ArrayExpression* array) {

}

void CppPrinter::visit(IdentifierExpression* id) {
    Class* klass;
    Variable* v;
    Def* def;

    isExpression = true;

    if (id->getName().compare("println") == 0) {
        output << "println";
        return;
    } else if (id->getName().compare("print") == 0) {
        output << "print";
        return;
    }

    Symbol* s = id->getSymbol();

    if (s != nullptr) {
        switch (s->getKind()) {
        case SYMBOL_CLASS_VARIABLE:
        case SYMBOL_LOCAL_VARIABLE:
        case SYMBOL_PARAMETER:
            v = (Variable*) s->getDescriptor();
            output << v->getUniqueCppName();
            break;

        case SYMBOL_DEF:
            def = (Def*) s->getDescriptor();
            output << def->getUniqueCppName();
            break;

        case SYMBOL_CLASS:
            klass = (Class*) s->getDescriptor();
            output << klass->getUniqueCppName();
            break;
        }
    }
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

void CppPrinter::printStart() {
    output << "#include <iostream>\n";
    output << "#include <vector>\n";
    output << "#include <sstream>\n";
    output << "#include <map>\n";
    output << "#include <cstdio>\n";

    output << "\nusing namespace std;\n\n";

    output << "typedef uint8_t u8;\n";
    output << "typedef uint16_t u16;\n";
    output << "typedef uint32_t u32;\n";
    output << "typedef uint64_t u64;\n";
    output << "typedef int8_t i8;\n";
    output << "typedef int16_t i16;\n";
    output << "typedef int32_t i32;\n";
    output << "typedef int64_t i64;\n\n";

    output << "void print(char v) { std::cout << v; }\n";
    output << "void print(int v) { std::cout << v; }\n";
    output << "void print(float v) { std::cout << v; }\n";
    output << "void print(double v) { std::cout << v; }\n";
    output << "void print(char* v) { std::cout << v; }\n";

    output << "void println(char v) { std::cout << v << '\\n'; }\n";
    output << "void println(int v) { std::cout << v << '\\n'; }\n";
    output << "void println(float v) { std::cout << v << '\\n'; }\n";
    output << "void println(double v) { std::cout << v << '\\n'; }\n";
    output << "void println(char* v) { std::cout << v << '\\n'; }\n";
    output << "\n";
}

void CppPrinter::printEnd() {
    output << "int main(int argc, char* argv[]) {\n    ";
    output << mainDef->getUniqueCppName() << "();\n";
    output << "    return 0;\n";
    output << "}";
}

void CppPrinter::generatePrototypes(SourceFile* file) {
    for (int i = 0; i < file->n_classes(); ++i) {
        generatePrototype(file->getClass(i));
    }

    output << '\n';

    for (int i = 0; i < file->n_defs(); ++i) {
        generatePrototype(file->getDef(i));
    }

    output << '\n';
}

void CppPrinter::generatePrototype(Def* def) {
    def->getReturnType()->accept(this);
    output << " " << def->getUniqueCppName() << "(";

    generateDefParameters(def);
    output << ");\n";
}

void CppPrinter::generatePrototype(Class* klass) {
    output << "class " << klass->getUniqueCppName() << ";\n";
}

void CppPrinter::generateDefParameters(Def* def) {
    int i;

    if (def->n_parameters() > 0) {
        for (i = 0; i < def->n_parameters() - 1; ++i) {
            def->getParameter(i)->accept(this);
            output << ", ";
        }

        def->getParameter(i)->accept(this);
    }
}

void CppPrinter::generateDefLocalVariables(Def* def) {
    for (int i = 0; i < def->n_local_variables(); ++i) {
        def->getLocalVariable(i)->accept(this);
    }
}
