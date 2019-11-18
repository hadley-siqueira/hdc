#ifndef HDC_SYMBOL_H
#define HDC_SYMBOL_H

#include "ast/AST.h"

namespace hdc {
    typedef enum SymbolKind {
        SYMBOL_DEF,
        SYMBOL_METHOD,
        SYMBOL_PARAMETER,
        SYMBOL_LOCAL_VARIABLE
    } SymbolKind;

    class Symbol {
        /* Constructors */
        public:
            Symbol(Def* def);
            Symbol(LocalVariable* var);
            Symbol(Parameter* parameter);

            SymbolKind getKind() const;
            void setKind(const SymbolKind& value);

            void* getDescriptor() const;
            void setDescriptor(void* value);

        private:
            SymbolKind kind;
            void* descriptor;
    };
}

#endif // SYMBOL_H
