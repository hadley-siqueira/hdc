#ifndef HDC_ASTNODE_H
#define HDC_ASTNODE_H

#include "visitors/Visitor.h"

namespace hdc {
    enum ASTKind {
        AST_PROGRAM,
        AST_SOURCE,
        AST_CLASS,
        AST_STRUCT,
        AST_DEF,
        AST_IDENTIFIER,
        AST_IMPORT,

        AST_CLASS_VARIABLE,
        AST_CONSTANT,
        AST_GLOBAL_CONSTANT,
        AST_GLOBAL_VARIABLE,
        AST_LOCAL_VARIABLE,
        AST_PARAMETER,
        AST_STRUCT_FIELD,

        /* Statements */
        AST_COMPOUND_STATEMENT,
        AST_FOR,
        AST_FOREACH,
        AST_IF,
        AST_ELIF,
        AST_ELSE,
        AST_WHILE,

        AST_RETURN,

        /* Types */
        AST_PRIMITIVE_TYPE,
        AST_CHAR_TYPE,
        AST_UCHAR_TYPE,
        AST_SHORT_TYPE,
        AST_USHORT_TYPE,
        AST_INT_TYPE,
        AST_UINT_TYPE,
        AST_LONG_TYPE,
        AST_ULONG_TYPE,
        AST_SYMBOL_TYPE,
        AST_VOID_TYPE,
        AST_BOOL_TYPE,
        AST_FLOAT_TYPE,
        AST_DOUBLE_TYPE,
        AST_INT8_TYPE,
        AST_INT16_TYPE,
        AST_INT32_TYPE,
        AST_INT64_TYPE,
        AST_UINT8_TYPE,
        AST_UINT16_TYPE,
        AST_UINT32_TYPE,
        AST_UINT64_TYPE,
        AST_POINTER_TYPE,
        AST_NAMED_TYPE,
        AST_FUNCTION_TYPE,

        /* operators */
        AST_AT,
        AST_DOLAR,
        AST_ADDRESS_OF,
        AST_ARROW,
        AST_DOT,
        AST_DEREFERENCE,
        AST_INDEX,
        AST_PARENTHESIS,
        AST_PRE_INCREMENT,
        AST_PRE_DECREMENT,
        AST_UNARY_PLUS,
        AST_UNARY_MINUS,

        AST_CALL,
        AST_SIZEOF,

        AST_BITWISE_AND,
        AST_BITWISE_NOT,
        AST_BITWISE_OR,
        AST_BITWISE_XOR,

        AST_SLL,
        AST_SRA,
        AST_SRL,

        AST_PLUS,
        AST_MINUS,
        AST_TIMES,
        AST_DIVISION,
        AST_MODULO,
        AST_INTEGER_DIVISION,

        AST_EQ,
        AST_NE,
        AST_GT,
        AST_GE,
        AST_LT,
        AST_LE,

        AST_LOGICAL_NOT,
        AST_LOGICAL_AND,
        AST_LOGICAL_OR,

        AST_ASSIGNMENT,
        AST_BITWISE_AND_ASSIGNMENT,
        AST_BITWISE_NOT_ASSIGNMENT,
        AST_BITWISE_OR_ASSIGNMENT,
        AST_BITWISE_XOR_ASSIGNMENT,
        AST_SLL_ASSIGNMENT,
        AST_SRA_ASSIGNMENT,
        AST_SRL_ASSIGNMENT,
        AST_PLUS_ASSIGNMENT,
        AST_MINUS_ASSIGNMENT,
        AST_TIMES_ASSIGNMENT,
        AST_DIVISION_ASSIGNMENT,
        AST_MODULO_ASSIGNMENT,
        AST_INTEGER_DIVISION_ASSIGNMENT,
        AST_SPECIAL_ASSIGNMENT,

        /* Literals */
        AST_LITERAL_NULL,
        AST_LITERAL_BOOL,
        AST_LITERAL_CHAR,
        AST_LITERAL_INTEGER,
        AST_LITERAL_FLOAT,
        AST_LITERAL_DOUBLE,
        AST_LITERAL_STRING,
        AST_LITERAL_SYMBOL,

        /* Lists, arrays, tuples and so on */
        AST_ARRAY_EXPRESSION,
        AST_LIST_EXPRESSION,
    };

    class ASTNode {
        public:
            ASTNode();
            void setKind(ASTKind kind);
            ASTKind getKind();

            ASTNode *getParentNode() const;
            void setParentNode(ASTNode *value);

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor)=0;

    protected:
            ASTKind kind;
            ASTNode* parentNode;
    };
}
#endif
