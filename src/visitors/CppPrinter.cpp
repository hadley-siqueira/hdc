#include <iostream>
#include <fstream>
#include "visitors/CppPrinter.h"

using namespace hdc;

CppPrinter::CppPrinter() {
    n_spaces = 0;
    mainDef = nullptr;
    isExpression = false;
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

void CppPrinter::visit(Program *program) {
    std::map<std::string, SourceFile*>::iterator it;

    printStart();

    for (it = program->begin(); it != program->end(); ++it) {
        generatePrototypes(it->second);
    }

    for (it = program->begin(); it != program->end(); ++it) {
        it->second->accept(this);
    }

    printEnd();
}

void hdc::CppPrinter::visit(SourceFile* file) {
    if (generatedSourceFiles.count(file) > 0) return;
    generatedSourceFiles.insert(file);

    for (int i = 0; i < file->n_imports(); ++i) {
        file->getImport(i)->accept(this);
    }

    output << "// file '" << file->getPath() << "'\n\n";

    for (int i = 0; i < file->n_classes(); ++i) {
        file->getClass(i)->accept(this);
    }

    for (int i = 0; i < file->n_defs(); ++i) {
        file->getDef(i)->accept(this);
    }
}

void CppPrinter::visit(Import* import) {
    import->getSourceFile()->accept(this);
}

void hdc::CppPrinter::visit(Class* klass) {
    if (generatedClasses.count(klass) > 0) return;
    generatedClasses.insert(klass);

    checkClassDependencies(klass);

    output << "class " << klass->getUniqueCppName();
    output << " {\npublic:\n";

    indent();

    for (int i = 0; i < klass->n_variables(); ++i) {
        print_indentation();
        klass->getVariable(i)->getType()->accept(this);
        output << " " << klass->getVariable(i)->getUniqueCppName() << ";\n";
    }

    output << '\n';

    for (int i = 0; i < klass->n_methods(); ++i) {
        klass->getMethod(i)->accept(this);
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

    if (variable->getType() != nullptr) {
        variable->getType()->accept(this);
    } else {
        output << "int";
    }

    output << " lv" << variable->getLocalName() << "_";
    output << variable->getName() << ";\n";
}

void CppPrinter::visit(GlobalVariable* variable) {

}

void CppPrinter::visit(ClassVariable *variable) {

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

void CppPrinter::visit(FunctionType *type) {

}

/* Statements */
void CppPrinter::visit(Statement* statement) {}

void CppPrinter::visit(CompoundStatement* statement) {
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
    std::vector<Variable*> vars = statement->getLiveVariables();

    for (int i = 0; i < vars.size(); ++i) {
        Variable* var = vars[i];
        Type* type = var->getType();

        if (type->getKind() == AST_NAMED_TYPE) {
            NamedType* n = (NamedType*) type;
            IdentifierExpression* id = n->getName();
            Symbol* sym = id->getSymbol();

            if (sym->getKind() == SYMBOL_CLASS) {
                Class* klass = (Class*) sym->getDescriptor();

                if (klass->getDestructor() != nullptr) {
                    print_indentation();
                    output << var->getUniqueCppName() << ".";
                    output << klass->getDestructor()->getUniqueCppName() << "();\n";
                }
            }
        }
    }

    print_indentation();
    output << "return";

    if (statement->getExpression()) {
        output << " ";
        statement->getExpression()->accept(this);
    }
}

void CppPrinter::visit(VariableDeclarationStatement *statement) {
    if (statement->getExpression() != nullptr) {
        statement->getName()->accept(this);
        output << " = ";
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

void CppPrinter::visit(LogicalAndExpression *expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " && ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(LogicalOrExpression *expression) {
    isExpression = true;

    output << "(";
    expression->getLeft()->accept(this);
    output << " || ";
    expression->getRight()->accept(this);
    output << ")";
}

void CppPrinter::visit(AssignmentExpression* expression) {
    isExpression = true;

    if (expression->getConstructorFlag()) {
        generateConstructorCall(expression);
    } else {
        expression->getLeft()->accept(this);
        output << " = ";
        expression->getRight()->accept(this);
    }
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

    if (expression->get_token().getKind() == TK_TRUE) {
        output << "true";
    } else {
        output << "false";
    }
}

void CppPrinter::visit(LiteralNullExpression *expression) {
    output << "nullptr";
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
        case SYMBOL_METHOD:
            def = (Def*) s->getDescriptor(id->getIdxOverloaded());
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
}

void CppPrinter::printEnd() {
    output << "int main(int argc, char* argv[]) {\n    ";

    if (mainDef != nullptr) {
        output << mainDef->getUniqueCppName() << "();\n";
    }
    output << "    return 0;\n";
    output << "}\n";
}

void CppPrinter::checkClassDependencies(Class *klass) {
    Type* t;
    Def* d;

    // check if variable types are already defined
    for (int i = 0; i < klass->n_variables(); ++i) {
        t = klass->getVariable(i)->getType();
        checkTypeDefinition(t);
    }

    for (int i = 0; i < klass->n_methods(); ++i) {
        d = klass->getMethod(i);
        t = d->getReturnType();
        checkTypeDefinition(t);

        for (int j = 0; j < d->n_parameters(); ++j) {
            t = d->getParameter(j)->getType();
            checkTypeDefinition(t);
        }

        for (int j = 0; j < d->n_local_variables(); ++j) {
            t = d->getLocalVariable(j)->getType();
            checkTypeDefinition(t);
        }
    }
}

void CppPrinter::checkTypeDefinition(Type *t) {
    ASTKind kind;
    NamedType* n;
    IdentifierExpression* id;
    Symbol* s;
    Class* c;

    kind = t->getKind();

    if (kind == AST_NAMED_TYPE) {
        n = (NamedType*) t;
        id = n->getName();
        s = id->getSymbol();

        switch (s->getKind()) {
        case SYMBOL_CLASS:
            c = (Class*) s->getDescriptor();
            c->accept(this);
            break;

        default:
            break;
        }
    }
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
    bool flag = false;

    for (int i = 0; i < def->n_local_variables(); ++i) {
        def->getLocalVariable(i)->accept(this);
        flag = true;
    }

    if (flag) {
        output << "\n";
    }
}

void CppPrinter::generateConstructorCall(AssignmentExpression *expression) {
    CallExpression* call;
    IdentifierExpression* id;
    int i = 0;

    expression->getLeft()->accept(this);

    call = (CallExpression*) expression->getRight();
    id = (IdentifierExpression*) call->getExpression();
    output << ".";
    id->accept(this);

    isExpression = true;
    output << "(";

    if (call->n_arguments() > 0) {
        for (i = 0; i < call->n_arguments() - 1; ++i) {
            call->getArgument(i)->accept(this);
            output << ", ";
        }

        call->getArgument(i)->accept(this);
    }

    output << ")";
}
