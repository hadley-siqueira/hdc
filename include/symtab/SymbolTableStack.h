#ifndef HDC_SYMBOLTABLE_STACK_H
#define HDC_SYMBOLTABLE_STACK_H

#include <stack>
#include "symtab/SymbolTable.h"

namespace hdc {
    /* This class is used together with visitors that uses SymbolTable. This class provides
     * abstractions to get in and out of scopes
     */
    class SymbolTableStack {
        /* Constructors */
        public:
            SymbolTableStack();
            SymbolTableStack(SymbolTable** symbolTable);

        /* Actions */
        public:
            void push(SymbolTable* symbolTable);
            void pop();

        private:
            void setSymbolTable();

        private:
            SymbolTable* current;

            // a pointer to an external pointer so one doesn't need to use top() all the time
            SymbolTable** symbolTable;
            std::stack<SymbolTable*> symbolTableStack;
    };
}

#endif
