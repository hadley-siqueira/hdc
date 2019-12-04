#ifndef LEX_H
#define LEX_H

#include <vector>
#include <stack>
#include <map>
#include "token/Token.h"

namespace hdc {
    class Lex {
        /* Constructors */
        public:
            Lex();

        public:
            std::vector<Token> getTokens(std::string filepath);

        /* Private methods */
        private:
            bool hasBase();

            bool isDigit();
            bool isAlpha();
            bool isOperator();
            bool isBinaryDigit();
            bool isOctalDigit();
            bool isHexaDigit();

            TokenKind getKeywordKind();

            void getIndentation();
            void skipWhitespace();
            void skipComment();
            void getDoubleQuoteString();
            void getSingleQuoteString();
            void getNumber();
            void getKeywordOrIdentifier();
            void getOperator();

            void advance();
            bool hasNext();
            void readFile(std::string filepath);
            void startLexem();
            void startLexem(bool flag);
            void endLexem();
            void endLexem(int offset);
            bool lookahead(char c);
            void createToken(TokenKind kind);
            void getNextToken();

        /* Private members */
        private:
            int row;
            int column;
            int idx;
            int lexemRow;
            int lexemColumn;
            int lexemBegin;
            int lexemEnd;
            bool hasLexem;
            bool newline;
            std::stack<TokenKind> blockStack;
            std::string buffer;
            std::vector<Token> tokens;
            std::stack<int> indentationStack;
            std::map<std::string, TokenKind> keywordsMap;
            std::map<std::string, TokenKind> operatorMap;
    };
}

#endif
