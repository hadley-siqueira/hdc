#include <sstream>
#include <iostream>
#include "token/Token.h"

using namespace hdc;

void Token::setKind(TokenKind kind) {
    this->kind = kind;
}


void Token::setLine(int line) {
    this->line = line;
}


void Token::setColumn(int column) {
    this->column = column;
}


void Token::setLexem(std::string& lexem) {
    this->lexem = lexem;
}


enum TokenKind Token::getKind() {
    return this->kind;
}


int Token::getLine() {
    return this->line;
}


int Token::getColumn() {
    return this->column;
}


std::string& Token::getLexem() {
    return this->lexem;
}


std::string Token::getKindAsString() {
    std::string kind_as_str;

    switch (kind) {
    case TK_DEF:
        kind_as_str = "TK_DEF";
        break;

    case TK_CLASS:
        kind_as_str = "TK_CLASS";
        break;

    case TK_VAR:
        kind_as_str = "TK_VAR";
        break;

    case TK_CONSTANT:
        kind_as_str = "TK_CONSTANT";
        break;


    case TK_STRUCT:
        kind_as_str = "TK_STRUCT";
        break;

    case TK_ENUM:
        kind_as_str = "TK_ENUM";
        break;

    case TK_UNION:
        kind_as_str = "TK_UNION";
        break;


    case TK_IF:
        kind_as_str = "TK_IF";
        break;

    case TK_ELIF:
        kind_as_str = "TK_ELIF";
        break;

    case TK_ELSE:
        kind_as_str = "TK_ELSE";
        break;


    case TK_FOR:
        kind_as_str = "TK_FOR";
        break;

    case TK_WHILE:
        kind_as_str = "TK_WHILE";
        break;


    case TK_CONTINUE:
        kind_as_str = "TK_CONTINUE";
        break;

    case TK_RETURN:
        kind_as_str = "TK_RETURN";
        break;

    case TK_GOTO:
        kind_as_str = "TK_GOTO";
        break;

    case TK_BREAK:
        kind_as_str = "TK_BREAK";
        break;

    case TK_YIELD:
        kind_as_str = "TK_YIELD";
        break;


    case TK_FROM:
        kind_as_str = "TK_FROM";
        break;

    case TK_AS:
        kind_as_str = "TK_AS";
        break;

    case TK_IMPORT:
        kind_as_str = "TK_IMPORT";
        break;

    case TK_DO:
        kind_as_str = "TK_DO";
        break;

    case TK_IN:
        kind_as_str = "TK_IN";
        break;

    case TK_PASS:
        kind_as_str = "TK_PASS";
        break;


    case TK_NEW:
        kind_as_str = "TK_NEW";
        break;

    case TK_DELETE:
        kind_as_str = "TK_DELETE";
        break;

    case TK_CASE:
        kind_as_str = "TK_CASE";
        break;

    case TK_DEFAULT:
        kind_as_str = "TK_DEFAULT";
        break;

    case TK_WITH:
        kind_as_str = "TK_WITH";
        break;

    case TK_SIZEOF:
        kind_as_str = "TK_SIZEOF";
        break;


    case TK_AND:
        kind_as_str = "TK_AND";
        break;

    case TK_OR:
        kind_as_str = "TK_OR";
        break;

    case TK_NOT:
        kind_as_str = "TK_NOT";
        break;


    case TK_U8:
        kind_as_str = "TK_U8";
        break;

    case TK_U16:
        kind_as_str = "TK_U16";
        break;

    case TK_U32:
        kind_as_str = "TK_U32";
        break;

    case TK_U64:
        kind_as_str = "TK_U64";
        break;

    case TK_I8:
        kind_as_str = "TK_I8";
        break;

    case TK_I16:
        kind_as_str = "TK_I16";
        break;

    case TK_I32:
        kind_as_str = "TK_I32";
        break;

    case TK_I64:
        kind_as_str = "TK_I64";
        break;


    case TK_VOID:
        kind_as_str = "TK_VOID";
        break;

    case TK_SYMBOL:
        kind_as_str = "TK_SYMBOL";
        break;

    case TK_BOOL:
        kind_as_str = "TK_BOOL";
        break;

    case TK_UCHAR:
        kind_as_str = "TK_UCHAR";
        break;

    case TK_CHAR:
        kind_as_str = "TK_CHAR";
        break;

    case TK_USHORT:
        kind_as_str = "TK_USHORT";
        break;

    case TK_SHORT:
        kind_as_str = "TK_SHORT";
        break;

    case TK_UINT:
        kind_as_str = "TK_UINT";
        break;

    case TK_INT:
        kind_as_str = "TK_INT";
        break;

    case TK_ULONG:
        kind_as_str = "TK_ULONG";
        break;

    case TK_LONG:
        kind_as_str = "TK_LONG";
        break;

    case TK_FLOAT:
        kind_as_str = "TK_FLOAT";
        break;

    case TK_DOUBLE:
        kind_as_str = "TK_DOUBLE";
        break;



    /* Identifiers and literals */
    case TK_ID:
        kind_as_str = "TK_ID";
        break;

    case TK_TRUE:
        kind_as_str = "TK_TRUE";
        break;

    case TK_FALSE:
        kind_as_str = "TK_FALSE";
        break;

    case TK_NULL:
        kind_as_str = "TK_NULL";
        break;

    case TK_LITERAL_CHAR:
        kind_as_str = "TK_LITERAL_CHAR";
        break;

    case TK_LITERAL_INTEGER:
        kind_as_str = "TK_LITERAL_INTEGER";
        break;

    case TK_LITERAL_FLOAT:
        kind_as_str = "TK_LITERAL_FLOAT";
        break;

    case TK_LITERAL_DOUBLE:
        kind_as_str = "TK_LITERAL_DOUBLE";
        break;

    case TK_LITERAL_STRING:
        kind_as_str = "TK_LITERAL_STRING";
        break;

    case TK_LITERAL_SYMBOL:
        kind_as_str = "TK_LITERAL_SYMBOL";
        break;


    /* Operators */

    /* arithmetic */
    case TK_PLUS:
        kind_as_str = "TK_PLUS";
        break;

    case TK_MINUS:
        kind_as_str = "TK_MINUS";
        break;

    case TK_TIMES:
        kind_as_str = "TK_TIMES";
        break;

    case TK_DIVISION:
        kind_as_str = "TK_DIVISION";
        break;

    case TK_INTEGER_DIVISION:
        kind_as_str = "TK_INTEGER_DIVISION";
        break;

    case TK_MODULO:
        kind_as_str = "TK_MODULO";
        break;

    case TK_POWER:
        kind_as_str = "TK_POWER";
        break;


    case TK_INC:
        kind_as_str = "TK_INC";
        break;

    case TK_DEC:
        kind_as_str = "TK_DEC";
        break;


    /* bitwise */
    case TK_BITWISE_AND:
        kind_as_str = "TK_BITWISE_AND";
        break;

    case TK_BITWISE_NOT:
        kind_as_str = "TK_BITWISE_NOT";
        break;

    case TK_BITWISE_OR:
        kind_as_str = "TK_BITWISE_OR";
        break;

    case TK_BITWISE_XOR:
        kind_as_str = "TK_BITWISE_XOR";
        break;

    case TK_SLL:
        kind_as_str = "TK_SLL";
        break;

    case TK_SRL:
        kind_as_str = "TK_SRL";
        break;

    case TK_SRA:
        kind_as_str = "TK_SRA";
        break;


    /* member access operators */
    case TK_ARROW:
        kind_as_str = "TK_ARROW";
        break;

    case TK_DOT:
        kind_as_str = "TK_DOT";
        break;


    /* scope */
    case TK_DOLAR:
        kind_as_str = "TK_DOLAR";
        break;

    case TK_SCOPE:
        kind_as_str = "TK_SCOPE";
        break;


    /* ranges */
    case TK_INCLUSIVE_RANGE:
        kind_as_str = "TK_INCLUSIVE_RANGE";
        break;

    case TK_EXCLUSIVE_RANGE:
        kind_as_str = "TK_EXCLUSIVE_RANGE";
        break;


    /* relational operators */
    case TK_EQ:
        kind_as_str = "TK_EQ";
        break;

    case TK_NE:
        kind_as_str = "TK_NE";
        break;

    case TK_GT:
        kind_as_str = "TK_GT";
        break;

    case TK_LT:
        kind_as_str = "TK_LT";
        break;

    case TK_GE:
        kind_as_str = "TK_GE";
        break;

    case TK_LE:
        kind_as_str = "TK_LE";
        break;


    /* logical operators */
    case TK_LOGICAL_AND:
        kind_as_str = "TK_LOGICAL_AND";
        break;

    case TK_LOGICAL_OR:
        kind_as_str = "TK_LOGICAL_OR";
        break;

    case TK_LOGICAL_NOT:
        kind_as_str = "TK_LOGICAL_NOT";
        break;


    /* conditional */
    case TK_TERNARY:
        kind_as_str = "TK_TERNARY";
        break;


    /* assignments */
    case TK_ASSIGNMENT:
        kind_as_str = "TK_ASSIGNMENT";
        break;

    case TK_BITWISE_AND_ASSIGNMENT:
        kind_as_str = "TK_BITWISE_AND_ASSIGNMENT";
        break;

    case TK_BITWISE_XOR_ASSIGNMENT:
        kind_as_str = "TK_BITWISE_XOR_ASSIGNMENT";
        break;

    case TK_BITWISE_OR_ASSIGNMENT:
        kind_as_str = "TK_BITWISE_OR_ASSIGNMENT";
        break;

    case TK_BITWISE_NOT_ASSIGNMENT:
        kind_as_str = "TK_BITWISE_NOT_ASSIGNMENT";
        break;

    case TK_DIVISION_ASSIGNMENT:
        kind_as_str = "TK_DIVISION_ASSIGNMENT";
        break;

    case TK_INTEGER_DIVISION_ASSIGNMENT:
        kind_as_str = "TK_INTEGER_DIVISION_ASSIGNMENT";
        break;

    case TK_MINUS_ASSIGNMENT:
        kind_as_str = "TK_MINUS_ASSIGNMENT";
        break;

    case TK_MODULO_ASSIGNMENT:
        kind_as_str = "TK_MODULO_ASSIGNMENT";
        break;

    case TK_PLUS_ASSIGNMENT:
        kind_as_str = "TK_PLUS_ASSIGNMENT";
        break;

    case TK_TIMES_ASSIGNMENT:
        kind_as_str = "TK_TIMES_ASSIGNMENT";
        break;

    case TK_SLL_ASSIGNMENT:
        kind_as_str = "TK_SLL_ASSIGNMENT";
        break;

    case TK_SRA_ASSIGNMENT:
        kind_as_str = "TK_SRA_ASSIGNMENT";
        break;

    case TK_SRL_ASSIGNMENT:
        kind_as_str = "TK_SRL_ASSIGNMENT";
        break;

    case TK_SPECIAL_ASSIGNMENT:
        kind_as_str = "TK_SPECIAL_ASSIGNMENT";
        break;


    /* others */
    case TK_HASH_ARROW:
        kind_as_str = "TK_HASH_ARROW";
        break;


    /* punctuation */
    case TK_NEWLINE:
        kind_as_str = "TK_NEWLINE";
        break;

    case TK_EOF:
        kind_as_str = "TK_EOF";
        break;

    case TK_AT:
        kind_as_str = "TK_AT";
        break;

    case TK_BEGIN:
        kind_as_str = "TK_BEGIN";
        break;

    case TK_END:
        kind_as_str = "TK_END";
        break;

    case TK_COLON:
        kind_as_str = "TK_COLON";
        break;

    case TK_COMMA:
        kind_as_str = "TK_COMMA";
        break;

    case TK_SEMICOLON:
        kind_as_str = "TK_SEMICOLON";
        break;

    case TK_LEFT_CURLY_BRACKET:
        kind_as_str = "TK_LEFT_CURLY_BRACKET";
        break;

    case TK_LEFT_PARENTHESIS:
        kind_as_str = "TK_LEFT_PARENTHESIS";
        break;

    case TK_LEFT_SQUARE_BRACKET:
        kind_as_str = "TK_LEFT_SQUARE_BRACKET";
        break;

    case TK_RIGHT_CURLY_BRACKET:
        kind_as_str = "TK_RIGHT_CURLY_BRACKET";
        break;

    case TK_RIGHT_PARENTHESIS:
        kind_as_str = "TK_RIGHT_PARENTHESIS";
        break;

    case TK_RIGHT_SQUARE_BRACKET:
        kind_as_str = "TK_RIGHT_SQUARE_BRACKET";
        break;
    }

    return kind_as_str;
}

std::string Token::getKindAsPrettyString() {
    std::string kind_as_str;

    switch (kind) {
    case TK_DEF:
        kind_as_str = "def";
        break;

    case TK_CLASS:
        kind_as_str = "class";
        break;

    case TK_VAR:
        kind_as_str = "var";
        break;

    case TK_CONSTANT:
        kind_as_str = "const";
        break;


    case TK_STRUCT:
        kind_as_str = "struct";
        break;

    case TK_ENUM:
        kind_as_str = "enum";
        break;

    case TK_UNION:
        kind_as_str = "union";
        break;


    case TK_IF:
        kind_as_str = "if";
        break;

    case TK_ELIF:
        kind_as_str = "elif";
        break;

    case TK_ELSE:
        kind_as_str = "else";
        break;


    case TK_FOR:
        kind_as_str = "for";
        break;

    case TK_WHILE:
        kind_as_str = "while";
        break;


    case TK_CONTINUE:
        kind_as_str = "continue";
        break;

    case TK_RETURN:
        kind_as_str = "return";
        break;

    case TK_GOTO:
        kind_as_str = "goto";
        break;

    case TK_BREAK:
        kind_as_str = "break";
        break;

    case TK_YIELD:
        kind_as_str = "yield";
        break;


    case TK_FROM:
        kind_as_str = "from";
        break;

    case TK_AS:
        kind_as_str = "as";
        break;

    case TK_IMPORT:
        kind_as_str = "import";
        break;

    case TK_DO:
        kind_as_str = "do";
        break;

    case TK_IN:
        kind_as_str = "in";
        break;

    case TK_PASS:
        kind_as_str = "pass";
        break;


    case TK_NEW:
        kind_as_str = "new";
        break;

    case TK_DELETE:
        kind_as_str = "delete";
        break;

    case TK_CASE:
        kind_as_str = "case";
        break;

    case TK_DEFAULT:
        kind_as_str = "default";
        break;

    case TK_WITH:
        kind_as_str = "with";
        break;

    case TK_SIZEOF:
        kind_as_str = "sizeof";
        break;


    case TK_AND:
        kind_as_str = "and";
        break;

    case TK_OR:
        kind_as_str = "or";
        break;

    case TK_NOT:
        kind_as_str = "not";
        break;


    case TK_U8:
        kind_as_str = "u8";
        break;

    case TK_U16:
        kind_as_str = "u16";
        break;

    case TK_U32:
        kind_as_str = "u32";
        break;

    case TK_U64:
        kind_as_str = "u64";
        break;

    case TK_I8:
        kind_as_str = "i8";
        break;

    case TK_I16:
        kind_as_str = "i16";
        break;

    case TK_I32:
        kind_as_str = "i32";
        break;

    case TK_I64:
        kind_as_str = "i64";
        break;


    case TK_VOID:
        kind_as_str = "void";
        break;

    case TK_SYMBOL:
        kind_as_str = "symbol";
        break;

    case TK_BOOL:
        kind_as_str = "bool";
        break;

    case TK_UCHAR:
        kind_as_str = "uchar";
        break;

    case TK_CHAR:
        kind_as_str = "char";
        break;

    case TK_USHORT:
        kind_as_str = "ushort";
        break;

    case TK_SHORT:
        kind_as_str = "short";
        break;

    case TK_UINT:
        kind_as_str = "uint";
        break;

    case TK_INT:
        kind_as_str = "int";
        break;

    case TK_ULONG:
        kind_as_str = "ulong";
        break;

    case TK_LONG:
        kind_as_str = "long";
        break;

    case TK_FLOAT:
        kind_as_str = "float";
        break;

    case TK_DOUBLE:
        kind_as_str = "double";
        break;



    /* Identifiers and literals */
    case TK_ID:
        kind_as_str = "identifier";
        break;

    case TK_TRUE:
        kind_as_str = "true";
        break;

    case TK_FALSE:
        kind_as_str = "false";
        break;

    case TK_NULL:
        kind_as_str = "null";
        break;

    case TK_LITERAL_CHAR:
        kind_as_str = "literal char";
        break;

    case TK_LITERAL_INTEGER:
        kind_as_str = "literal integer";
        break;

    case TK_LITERAL_FLOAT:
        kind_as_str = "literal float";
        break;

    case TK_LITERAL_DOUBLE:
        kind_as_str = "literal double";
        break;

    case TK_LITERAL_STRING:
        kind_as_str = "literal string";
        break;

    case TK_LITERAL_SYMBOL:
        kind_as_str = "literal symbol";
        break;


    /* Operators */

    /* arithmetic */
    case TK_PLUS:
        kind_as_str = "+";
        break;

    case TK_MINUS:
        kind_as_str = "-";
        break;

    case TK_TIMES:
        kind_as_str = "*";
        break;

    case TK_DIVISION:
        kind_as_str = "/";
        break;

    case TK_INTEGER_DIVISION:
        kind_as_str = "//";
        break;

    case TK_MODULO:
        kind_as_str = "%";
        break;

    case TK_POWER:
        kind_as_str = "**";
        break;


    case TK_INC:
        kind_as_str = "++";
        break;

    case TK_DEC:
        kind_as_str = "--";
        break;


    /* bitwise */
    case TK_BITWISE_AND:
        kind_as_str = "&";
        break;

    case TK_BITWISE_NOT:
        kind_as_str = "~";
        break;

    case TK_BITWISE_OR:
        kind_as_str = "|";
        break;

    case TK_BITWISE_XOR:
        kind_as_str = "^";
        break;

    case TK_SLL:
        kind_as_str = "<<";
        break;

    case TK_SRL:
        kind_as_str = ">>>";
        break;

    case TK_SRA:
        kind_as_str = ">>";
        break;


    /* member access operators */
    case TK_ARROW:
        kind_as_str = "->";
        break;

    case TK_DOT:
        kind_as_str = ".";
        break;


    /* scope */
    case TK_DOLAR:
        kind_as_str = "$";
        break;

    case TK_SCOPE:
        kind_as_str = "::";
        break;


    /* ranges */
    case TK_INCLUSIVE_RANGE:
        kind_as_str = "..";
        break;

    case TK_EXCLUSIVE_RANGE:
        kind_as_str = "...";
        break;


    /* relational operators */
    case TK_EQ:
        kind_as_str = "==";
        break;

    case TK_NE:
        kind_as_str = "!=";
        break;

    case TK_GT:
        kind_as_str = ">";
        break;

    case TK_LT:
        kind_as_str = "<";
        break;

    case TK_GE:
        kind_as_str = ">=";
        break;

    case TK_LE:
        kind_as_str = "<=";
        break;


    /* logical operators */
    case TK_LOGICAL_AND:
        kind_as_str = "&&";
        break;

    case TK_LOGICAL_OR:
        kind_as_str = "||";
        break;

    case TK_LOGICAL_NOT:
        kind_as_str = "!";
        break;


    /* conditional */
    case TK_TERNARY:
        kind_as_str = "?";
        break;


    /* assignments */
    case TK_ASSIGNMENT:
        kind_as_str = "=";
        break;

    case TK_BITWISE_AND_ASSIGNMENT:
        kind_as_str = "&=";
        break;

    case TK_BITWISE_XOR_ASSIGNMENT:
        kind_as_str = "^=";
        break;

    case TK_BITWISE_OR_ASSIGNMENT:
        kind_as_str = "|=";
        break;

    case TK_BITWISE_NOT_ASSIGNMENT:
        kind_as_str = "~=";
        break;

    case TK_DIVISION_ASSIGNMENT:
        kind_as_str = "/=";
        break;

    case TK_INTEGER_DIVISION_ASSIGNMENT:
        kind_as_str = "//=";
        break;

    case TK_MINUS_ASSIGNMENT:
        kind_as_str = "-=";
        break;

    case TK_MODULO_ASSIGNMENT:
        kind_as_str = "%=";
        break;

    case TK_PLUS_ASSIGNMENT:
        kind_as_str = "+=";
        break;

    case TK_TIMES_ASSIGNMENT:
        kind_as_str = "*=";
        break;

    case TK_SLL_ASSIGNMENT:
        kind_as_str = "<<=";
        break;

    case TK_SRA_ASSIGNMENT:
        kind_as_str = ">>=";
        break;

    case TK_SRL_ASSIGNMENT:
        kind_as_str = ">>>=";
        break;

    case TK_SPECIAL_ASSIGNMENT:
        kind_as_str = ":=";
        break;


    /* others */
    case TK_HASH_ARROW:
        kind_as_str = "=>";
        break;


    /* punctuation */
    case TK_NEWLINE:
        kind_as_str = "\\n";
        break;

    case TK_EOF:
        kind_as_str = "EOF";
        break;

    case TK_AT:
        kind_as_str = "@";
        break;

    case TK_BEGIN:
        kind_as_str = "begin";
        break;

    case TK_END:
        kind_as_str = "end";
        break;

    case TK_COLON:
        kind_as_str = ":";
        break;

    case TK_COMMA:
        kind_as_str = ",";
        break;

    case TK_SEMICOLON:
        kind_as_str = ";";
        break;

    case TK_LEFT_CURLY_BRACKET:
        kind_as_str = "{";
        break;

    case TK_LEFT_PARENTHESIS:
        kind_as_str = "(";
        break;

    case TK_LEFT_SQUARE_BRACKET:
        kind_as_str = "[";
        break;

    case TK_RIGHT_CURLY_BRACKET:
        kind_as_str = "}";
        break;

    case TK_RIGHT_PARENTHESIS:
        kind_as_str = ")";
        break;

    case TK_RIGHT_SQUARE_BRACKET:
        kind_as_str = "]";
        break;
    }

    return kind_as_str;
}

std::string Token::toStr() {
    std::stringstream ss;

    ss << "(" << getKindAsString() << ", " << line
        << ", " << column;

    if (lexem.size() > 0) {
        ss << ", " << lexem;
    }

    ss << ")";

    return ss.str();
}
