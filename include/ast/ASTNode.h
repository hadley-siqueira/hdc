#ifndef HDC_ASTNODE_H
#define HDC_ASTNODE_H

#include "visitors/Visitor.h"

namespace hdc {
    enum ASTKind {
        AST_SOURCE,
        AST_CLASS,
        AST_IDENTIFIER,

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

        /* operators */
        AST_CALL,
        AST_PLUS,
        AST_MINUS,
        AST_TIMES
    };

    class ASTNode {
        public:
            ASTNode();
            void setKind(ASTKind kind);
            ASTKind getKind();

        /* Visitors */
        public:
            virtual void accept(Visitor* visitor)=0;

            ASTNode *getParentNode() const;
            void setParentNode(ASTNode *value);

    protected:
            ASTKind kind;
            ASTNode* parentNode;
    };
}
#endif
