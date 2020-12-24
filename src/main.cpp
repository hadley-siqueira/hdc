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

int main(int argc, char* argv[]) {
    Driver driver;

    driver.setFlags(argc, argv);
    driver.run();
    driver.showLogs();

    return 0;
}
