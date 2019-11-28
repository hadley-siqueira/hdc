#include <iostream>
#include <vector>

#include "token/Token.h"
#include "lex/Lex.h"
#include "parser/Parser.h"
#include "ast/AST.h"
#include "visitors/PrettyPrinter.h"
#include "visitors/SymbolTableBuilderVisitor.h"
#include "visitors/TypeCheckerVisitor.h"
#include "visitors/CppPrinter.h"
#include "driver/Driver.h"

using namespace std;
using namespace hdc;

void testLex(string path) {
    Lex lex;
    std::vector<Token> tokens;

    tokens = lex.getTokens(path);

    std::cout << tokens.size() << std::endl;

    for (int i = 0; i < tokens.size(); ++i) {
        std::cout << tokens[i].toStr() << std::endl;
    }
}

void testParser(string path) {
    Parser parser;
    SourceFile* file;

    file = parser.read(path);
    delete file;
}

void testPrettyPrinter(string path) {
    Parser parser;
    PrettyPrinter printer;
    SourceFile* file;

    file = parser.read(path);
    file->accept(&printer);
    printer.print();

    delete file;
}

void testSymbolTableBuilder(string path) {
    Parser parser;
    PrettyPrinter printer;
    SymbolTableBuilderVisitor sbuilder;
    SourceFile* file;

    file = parser.read(path);


    file->accept(&sbuilder);
    file->accept(&printer);
    printer.print();

    delete file;
}

void testCppPrinter(string path) {
    Parser parser;
    CppPrinter printer;
    SourceFile* file;
    SymbolTableBuilderVisitor sbuilder;
    TypeCheckerVisitor typer;

    file = parser.read(path);

    file->accept(&sbuilder);
    file->accept(&typer);
    file->accept(&printer);

    printer.print();
    printer.save("/tmp/test.cpp");

    delete file;
}

int main(int argc, char* argv[]) {
    string path = "/home/hadley/Projetos/hdc/samples/ppm5.hd";
    Driver driver;

    //testLex(path);
    //testParser(path);
    testPrettyPrinter(path);
    //testSymbolTableBuilder(path);
    testCppPrinter(path);

    return 0;
}
