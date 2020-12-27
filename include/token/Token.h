#ifndef TOKEN_H
#define TOKEN_H

#include <string>

namespace hdc {
    enum TokenKind {
        /* Keywords */
        TK_DEF,
        TK_CLASS,
        TK_VAR,
        TK_CONSTANT,

        TK_STRUCT,
        TK_ENUM,
        TK_UNION,

        TK_IF,
        TK_ELIF,
        TK_ELSE,

        TK_FOR,
        TK_WHILE,

        TK_CONTINUE,
        TK_RETURN,
        TK_GOTO,
        TK_BREAK,
        TK_YIELD,

        TK_FROM,
        TK_AS,
        TK_IMPORT,
        TK_DO,
        TK_IN,
        TK_PASS,

        TK_NEW,
        TK_DELETE,
        TK_CASE,
        TK_DEFAULT,
        TK_WITH,
        TK_SIZEOF,

        TK_AND,
        TK_OR,
        TK_NOT,

        /* types */
        TK_U8, TK_U16, TK_U32, TK_U64,
        TK_I8, TK_I16, TK_I32, TK_I64,

        TK_VOID,
        TK_SYMBOL,
        TK_BOOL,
        TK_UCHAR, TK_CHAR,
        TK_USHORT, TK_SHORT,
        TK_UINT, TK_INT,
        TK_ULONG, TK_LONG,
        TK_FLOAT,
        TK_DOUBLE,


        /* Identifiers and literals */
        TK_ID,
        TK_TRUE,
        TK_FALSE,
        TK_NULL,
        TK_LITERAL_CHAR,
        TK_LITERAL_INTEGER,
        TK_LITERAL_FLOAT,
        TK_LITERAL_DOUBLE,
        TK_LITERAL_STRING,
        TK_LITERAL_SYMBOL,

        /* Operators */

        /* arithmetic */
        TK_PLUS,
        TK_MINUS,
        TK_TIMES,
        TK_DIVISION,
        TK_INTEGER_DIVISION,
        TK_MODULO,
        TK_POWER,

        TK_INC,
        TK_DEC,

        /* bitwise */
        TK_BITWISE_AND,
        TK_BITWISE_NOT,
        TK_BITWISE_OR,
        TK_BITWISE_XOR,
        TK_SLL,
        TK_SRL,
        TK_SRA,

        /* member access operators */
        TK_ARROW,
        TK_DOT,

        /* scope */
        TK_DOLAR,
        TK_SCOPE,

        /* ranges */
        TK_INCLUSIVE_RANGE,
        TK_EXCLUSIVE_RANGE,

        /* relational operators */
        TK_EQ,
        TK_NE,
        TK_GT,
        TK_LT,
        TK_GE,
        TK_LE,

        /* logical operators */
        TK_LOGICAL_AND,
        TK_LOGICAL_OR,
        TK_LOGICAL_NOT,

        /* conditional */
        TK_TERNARY,

        /* assignments */
        TK_ASSIGNMENT,
        TK_BITWISE_AND_ASSIGNMENT,
        TK_BITWISE_XOR_ASSIGNMENT,
        TK_BITWISE_OR_ASSIGNMENT,
        TK_BITWISE_NOT_ASSIGNMENT,
        TK_DIVISION_ASSIGNMENT,
        TK_INTEGER_DIVISION_ASSIGNMENT,
        TK_MINUS_ASSIGNMENT,
        TK_MODULO_ASSIGNMENT,
        TK_PLUS_ASSIGNMENT,
        TK_TIMES_ASSIGNMENT,
        TK_SLL_ASSIGNMENT,
        TK_SRA_ASSIGNMENT,
        TK_SRL_ASSIGNMENT,
        TK_SPECIAL_ASSIGNMENT,

        /* others */
        TK_HASH_ARROW,

        /* punctuation */
        TK_NEWLINE,
        TK_EOF,
        TK_AT,
        TK_BEGIN,
        TK_END,
        TK_COLON,
        TK_COMMA,
        TK_SEMICOLON,
        TK_LEFT_CURLY_BRACKET,
        TK_LEFT_PARENTHESIS,
        TK_LEFT_SQUARE_BRACKET,
        TK_RIGHT_CURLY_BRACKET,
        TK_RIGHT_PARENTHESIS,
        TK_RIGHT_SQUARE_BRACKET,

        /* For debug purpose */
        TK_UNKNOWN
    };

    class Token {
        public:
            void setKind(TokenKind kind);
            void setLine(int line);
            void setColumn(int column);
            void setLexem(std::string& lexem);

            enum TokenKind getKind();
            int getLine();
            int getColumn();
            std::string& getLexem();
            std::string getKindAsString();
            std::string getKindAsPrettyString();
            std::string toStr();

        /* Private members */
        private:
            enum TokenKind kind;
            int line;
            int column;
            std::string lexem;
    };
}

#endif
