#ifndef HDC_STRUCT_H
#define HDC_STRUCT_H

#include <vector>

#include "ASTNode.h"
#include "ast/SourceFile.h"
#include "ast/IdentifierExpression.h"
#include "ast/StructField.h"
#include "symtab/SymbolTable.h"

namespace hdc {
    class SourceFile;
    class SymbolTable;

    class Struct : public ASTNode {
        /* Constructors */
        public:
            Struct();

        /* Destructors */
        public:
            ~Struct();

        /* Setters */
        public:
            void setName(Token& token);
            void setSuperStruct(IdentifierExpression* superStruct);

        /* Getters */
        public:
            std::string getName();
            IdentifierExpression* getSuperStruct();
            StructField* getField(int i);
            int getLine();
            int getColumn();

        /* Predicates */
        public:
            bool hasSuperStruct();
            int n_fields();

        public:
            void addField(StructField* field);

        /* Visitors */
        public:
            void accept(Visitor* visitor);

            SymbolTable* getSymbolTable() const;
            void setSymbolTable(SymbolTable* value);

        private:
            Token name;
            IdentifierExpression* superStruct;
            SourceFile* file;
            std::vector<StructField*> fields;
            SymbolTable* symbolTable;

    };
}

#endif
