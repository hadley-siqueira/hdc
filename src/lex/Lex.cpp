#include <iostream>
#include <fstream>
#include "lex/Lex.h"

using namespace hdc;

Lex::Lex() {
    this->row = 1;
    this->column = 1;
    this->idx = 0;
    this->lexemBegin = 0;
    this->lexemEnd = 0;
    this->newline = true;
    this->hasLexem = false;
    this->indentationStack.push(0);

    if (true) {
        keywordsMap["def"] = TK_DEF;
        keywordsMap["class"] = TK_CLASS;
        keywordsMap["var"] = TK_VAR;
        keywordsMap["const"] = TK_CONSTANT;
        keywordsMap["constant"] = TK_CONSTANT;

        keywordsMap["struct"] = TK_STRUCT;
        keywordsMap["enum"] = TK_ENUM;
        keywordsMap["union"] = TK_UNION;

        keywordsMap["new"] = TK_NEW;
        keywordsMap["delete"] = TK_DELETE;
        keywordsMap["case"] = TK_CASE;
        keywordsMap["default"] = TK_DEFAULT;
        keywordsMap["with"] = TK_WITH;
        keywordsMap["pass"] = TK_PASS;
        keywordsMap["do"] = TK_DO;
        keywordsMap["from"] = TK_FROM;
        keywordsMap["sizeof"] = TK_SIZEOF;

        keywordsMap["import"] = TK_IMPORT;
        keywordsMap["as"] = TK_AS;
        keywordsMap["in"] = TK_IN;
        keywordsMap["null"] = TK_NULL;

        keywordsMap["if"] = TK_IF;
        keywordsMap["elif"] = TK_ELIF;
        keywordsMap["else"] = TK_ELSE;

        keywordsMap["for"] = TK_FOR;
        keywordsMap["while"] = TK_WHILE;

        keywordsMap["break"] = TK_BREAK;
        keywordsMap["continue"] = TK_CONTINUE;
        keywordsMap["goto"] = TK_GOTO;
        keywordsMap["yield"] = TK_YIELD;
        keywordsMap["return"] = TK_RETURN;

        keywordsMap["and"] = TK_AND;
        keywordsMap["or"] = TK_OR;
        keywordsMap["not"] = TK_NOT;

        /* types */
        keywordsMap["u8"] = TK_U8;
        keywordsMap["u16"] = TK_U16;
        keywordsMap["u32"] = TK_U32;
        keywordsMap["u64"] = TK_U64;

        keywordsMap["i8"] = TK_I8;
        keywordsMap["i16"] = TK_I16;
        keywordsMap["i32"] = TK_I32;
        keywordsMap["i64"] = TK_I64;

        keywordsMap["void"] = TK_VOID;
        keywordsMap["symbol"] = TK_SYMBOL;
        keywordsMap["bool"] = TK_BOOL;
        keywordsMap["uchar"] = TK_UCHAR;
        keywordsMap["char"] = TK_CHAR;
        keywordsMap["ushort"] = TK_USHORT;
        keywordsMap["short"] = TK_SHORT;
        keywordsMap["uint"] = TK_UINT;
        keywordsMap["int"] = TK_INT;
        keywordsMap["ulong"] = TK_ULONG;
        keywordsMap["long"] = TK_LONG;
        keywordsMap["float"] = TK_FLOAT;
        keywordsMap["double"] = TK_DOUBLE;


        /* operators */

        /* increment and decrement */
        operatorMap["++"] = TK_INC;
        operatorMap["--"] = TK_DEC;

        /* arithmetic */
        operatorMap["+"] = TK_PLUS;
        operatorMap["-"] = TK_MINUS;
        operatorMap["*"] = TK_TIMES;
        operatorMap["/"] = TK_DIVISION;
        operatorMap["//"] = TK_INTEGER_DIVISION;
        operatorMap["%"] = TK_MODULO;
        operatorMap["**"] = TK_POWER;

        /* relational */
        operatorMap["=="] = TK_EQ;
        operatorMap["!="] = TK_NE;
        operatorMap[">"] = TK_GT;
        operatorMap["<"] = TK_LT;
        operatorMap[">="] = TK_GE;
        operatorMap["<="] = TK_LE;

        /* bitwise */
        operatorMap["&"] = TK_BITWISE_AND;
        operatorMap["|"] = TK_BITWISE_OR;
        operatorMap["^"] = TK_BITWISE_XOR;
        operatorMap["~"] = TK_BITWISE_NOT;
        operatorMap["<<"] = TK_SLL;
        operatorMap[">>"] = TK_SRA;
        operatorMap[">>>"] = TK_SRL;

        /* logical */
        operatorMap["&&"] = TK_LOGICAL_AND;
        operatorMap["||"] = TK_LOGICAL_OR;
        operatorMap["!"] = TK_LOGICAL_NOT;

        /* member access */
        operatorMap["->"] = TK_ARROW;
        operatorMap["."] = TK_DOT;

        /* scope */
        operatorMap["::"] = TK_SCOPE;
        operatorMap["$"] = TK_DOLAR;

        /* ranges */
        operatorMap[".."] = TK_INCLUSIVE_RANGE;
        operatorMap["..."] = TK_EXCLUSIVE_RANGE;

        /* ternary */
        operatorMap["?"] = TK_TERNARY;

        /* hash arrow*/
        operatorMap["=>"] = TK_HASH_ARROW;

        /* assignments */
        operatorMap["="] = TK_ASSIGNMENT;
        operatorMap["&="] = TK_BITWISE_AND_ASSIGNMENT;
        operatorMap["^="] = TK_BITWISE_XOR_ASSIGNMENT;
        operatorMap["|="] = TK_BITWISE_OR_ASSIGNMENT;
        operatorMap["~="] = TK_BITWISE_NOT_ASSIGNMENT;
        operatorMap["/="] = TK_DIVISION_ASSIGNMENT;
        operatorMap["//="] = TK_INTEGER_DIVISION_ASSIGNMENT;
        operatorMap["-="] = TK_MINUS_ASSIGNMENT;
        operatorMap["%="] = TK_MODULO_ASSIGNMENT;
        operatorMap["+="] = TK_PLUS_ASSIGNMENT;
        operatorMap["*="] = TK_TIMES_ASSIGNMENT;
        operatorMap["<<="] = TK_SLL_ASSIGNMENT;
        operatorMap[">>="] = TK_SRA_ASSIGNMENT;
        operatorMap[">>>="] = TK_SRL_ASSIGNMENT;
        operatorMap[":="] = TK_SPECIAL_ASSIGNMENT;

        /* punctuation */
        operatorMap["@"] = TK_AT;
        operatorMap[":"] = TK_COLON;
        operatorMap[","] = TK_COMMA;
        operatorMap[";"] = TK_SEMICOLON;
        operatorMap["("] = TK_LEFT_PARENTHESIS;
        operatorMap[")"] = TK_RIGHT_PARENTHESIS;
        operatorMap["["] = TK_LEFT_SQUARE_BRACKET;
        operatorMap["]"] = TK_RIGHT_SQUARE_BRACKET;
        operatorMap["{"] = TK_LEFT_CURLY_BRACKET;
        operatorMap["}"] = TK_RIGHT_CURLY_BRACKET;
    }
}


bool Lex::hasNext() {
    return idx < buffer.size();
}


bool Lex::hasBase() {
    bool flag;
    bool flag2;

    if (idx + 2 >= buffer.size()) return false;

    flag = buffer[idx + 1] == 'o' || buffer[idx + 1] == 'b' || buffer[idx + 1] == 'x';
    flag2 = buffer[idx + 1] >= '0' && buffer[idx + 1] <= '7';

    return buffer[idx] == '0' && (flag || flag2);
}


bool Lex::isDigit() {
    return buffer[idx] >= '0' && buffer[idx] <= '9';
}

bool Lex::isAlpha() {
    return buffer[idx] >= 'a' && buffer[idx] <= 'z' ||
           buffer[idx] >= 'A' && buffer[idx] <= 'Z' ||  
           buffer[idx] == '_';
}


bool Lex::isOperator() {
    char c = buffer[idx];

    return c == '(' || c == ')' || c == '[' || c == ']'
        || c == '{' || c == '}' || c == '+' || c == '-'
        || c == '*' || c == '/' || c == '%' || c == '!'
        || c == '&' || c == '|' || c == '~' || c ==  '='
        || c == '>' || c == '<' || c == '^' || c == '.'
        || c == '$' || c == ':' || c == '?' || c == '@'
        || c == ',' || c == ';'; 
}


bool Lex::isBinaryDigit() {
    return buffer[idx] == '0' || buffer[idx] == '1';
}


bool Lex::isOctalDigit() {
    return buffer[idx] >= '0' && buffer[idx] <= '7';
}


bool Lex::isHexaDigit() {
    return buffer[idx] >= '0' && buffer[idx] <= '9' ||
           buffer[idx] >= 'a' && buffer[idx] <= 'f' ||
           buffer[idx] >= 'A' && buffer[idx] <= 'F';
}


void Lex::readFile(std::string filepath) {
    char c;
    std::ifstream file;

    file.open(filepath.c_str());

    while (file.get(c)) {
        this->buffer += c;
    }

    file.close();
}


void Lex::advance() {
    if (!hasNext()) return;

    if (buffer[idx] == '\n') {
        ++row;
        column = 1;
        newline = true;
    } else {
        ++column;
    }

    ++idx;
}


void Lex::startLexem() {
    lexemBegin = idx;
    lexemRow = row;
    lexemColumn = column;
    hasLexem = false;
}


void Lex::startLexem(bool flag) {
    lexemBegin = idx;
    lexemRow = row;
    lexemColumn = column;
    hasLexem = flag;
}


void Lex::endLexem() {
    lexemEnd = idx;
}


bool Lex::lookahead(char c) {
    return idx < buffer.size() && buffer[idx] == c;
}


void Lex::getIndentation() {
    int n_spaces = 0;

    while (lookahead(' ')) {
        advance();
        ++n_spaces;
    }

    if (lookahead('#') || lookahead('\n')) {
        return;
    }

    newline = false;

    if (n_spaces > indentationStack.top()) {
        indentationStack.push(n_spaces);
        createToken(TK_BEGIN);
    } else {
        while (n_spaces < indentationStack.top()) {
            indentationStack.pop();
            createToken(TK_END);
        }
    }
}


void Lex::skipWhitespace() {
    while (lookahead(' ')) {
        advance();
    }
}


void Lex::skipComment() {
    while (!lookahead('\n')) {
        advance();
    }
}


void Lex::getDoubleQuoteString() {
    startLexem(true);
    advance();

    while (!lookahead('"')) {
        if (lookahead('\\')) {
            advance();
        }

        advance();
    }

    advance();
    endLexem();
    createToken(TK_LITERAL_STRING);
}


void Lex::getSingleQuoteString() {
    int steps = 0;

    startLexem(true);
    advance();

    while (!lookahead('\'')) {
        if (lookahead('\\')) {
            advance();
        }

        advance();
        ++steps;
    }

    advance();
    endLexem();

    if (steps > 1) {
        createToken(TK_LITERAL_STRING);
    } else {
        createToken(TK_LITERAL_CHAR);
    }
}


void Lex::getNumber() {
    TokenKind kind = TK_LITERAL_INTEGER;

    startLexem(true);

    if (hasBase()) {
        advance();

        if (lookahead('b')) {
            advance();

            while (isBinaryDigit()) {
                advance();
            }
        } else if (lookahead('o')) {
            advance();

            while (isOctalDigit()) {
                advance();
            }
        } else if (lookahead('x')) {
            advance(); 

            while (isHexaDigit()) {
                advance();
            }
        } else {
            while (isOctalDigit()) {
                advance();
            }
        }
    } else {
        while (isDigit()) {
            advance();
        }

        if (lookahead('.')) {
            advance();
            kind = TK_LITERAL_DOUBLE;

            while (isDigit()) {
                advance();
            }
        }

        if (lookahead('e') || lookahead('E')) {
            kind = TK_LITERAL_DOUBLE;
            advance();

            if (lookahead('-') || lookahead('+')) {
                advance();
            }

            while (isDigit()) {
                advance();
            }
        }

        if (lookahead('f') || lookahead('F')) {
            advance();
            kind = TK_LITERAL_FLOAT;
        }
    }

    endLexem();
    lexemEnd--;
    createToken(kind);
}


hdc::TokenKind Lex::getKeywordKind() {
    std::string lexem;

    for (int i = lexemBegin; i <= lexemEnd; ++i) {
        lexem += buffer[i];
    }

    if (keywordsMap.count(lexem) > 0) {
        return keywordsMap[lexem];
    }

    return TK_ID;
}


void Lex::getKeywordOrIdentifier() {
    TokenKind kind;
    startLexem(true);

    while (isAlpha() || isDigit()) {
        advance();
    }

    endLexem();
    lexemEnd--;

    kind = getKeywordKind();

    if (kind != TK_ID) {
        hasLexem = false;
    }

    createToken(kind);
}


void Lex::createToken(TokenKind kind) {
    Token token;
    std::string lexem;

    if (hasLexem) {
        hasLexem = false;

        for (int i = lexemBegin; i <= lexemEnd; ++i) {
            lexem += buffer[i];
        }

        token.setLine(lexemRow);
        token.setColumn(lexemColumn);
        token.setLexem(lexem);
    } else {
        token.setLine(row);
        token.setColumn(column);
    }

    token.setKind(kind);
    tokens.push_back(token);
}


void Lex::getOperator() {
    TokenKind kind;
    std::string lexem;

    for (int i = 0; i < 4; ++i) {
        lexem += buffer[idx + i];
    }

    while (lexem.size() > 0) {
        if (operatorMap.count(lexem) > 0) {
            kind = operatorMap[lexem];
            break;
        }

        lexem.pop_back();
    }

    if (lexem.size() > 0) {
        startLexem();

        for (int i = 0; i < lexem.size() - 1; ++i) {
            advance();
        }

        endLexem();
        advance();
        createToken(kind);
    } else {
        std::cout << "invalid operator\n";
    }
}


void Lex::getNextToken() {
    if (lookahead('\n')) {
        if (!newline) {
            createToken(TK_NEWLINE);
        }

        advance();
    } else if (lookahead('#')) {
        skipComment();
    } else if (newline) {
        getIndentation();
    } else if (lookahead(' ')) {
        skipWhitespace();
    } else if (lookahead('"')) {
        getDoubleQuoteString();
    } else if (lookahead('\'')) {
        getSingleQuoteString();
    } else if (isDigit()) {
        getNumber();
    } else if (isAlpha()) {
        getKeywordOrIdentifier();
    } else if (isOperator()) {
        getOperator();
    } else {
        std::cout << buffer[idx] << "\n";
    }
}


std::vector<hdc::Token> Lex::getTokens(std::string filepath) {
    readFile(filepath);

    while (hasNext()) {
        getNextToken();
    }

    // emit remaining dedents
    while (indentationStack.top() != 0) {
        indentationStack.pop();
        createToken(TK_END);
    }

    // emit EOF
    createToken(TK_EOF);

    return this->tokens;
}
