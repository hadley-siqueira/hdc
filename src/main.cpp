#include <iostream>
#include <vector>

#include "token/Token.h"
#include "lex/Lex.h"

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

int main(int argc, char* argv[]) {
    testLex("/home/hadley/Projetos/hdc/samples/simple0.hd");
    return 0;
}
