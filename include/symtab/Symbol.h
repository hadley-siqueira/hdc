#ifndef HDC_SYMBOL_H
#define HDC_SYMBOL_H

#include <vector>
#include "ast/AST.h"

namespace hdc {
    typedef enum SymbolKind {
        SYMBOL_CLASS,
        SYMBOL_DEF,
        SYMBOL_METHOD,
        SYMBOL_PARAMETER,
        SYMBOL_LOCAL_VARIABLE,
        SYMBOL_CLASS_VARIABLE,
        SYMBOL_GLOBAL_VARIABLE,
        SYMBOL_GLOBAL_CONSTANT
    } SymbolKind;

    class Symbol {
        /* Constructors */
        public:
            Symbol(Class* klass);
            Symbol(Def* def);
            Symbol(LocalVariable* var);
            Symbol(Parameter* parameter);
            Symbol(class ClassVariable* var);
            Symbol(class GlobalVariable* var);

            SymbolKind getKind() const;
            void setKind(const SymbolKind& value);

            void* getDescriptor() const;
            void setDescriptor(void* value);

            int getLine() const;
            void setLine(int value);

            int getColumn() const;
            void setColumn(int value);

            Type* getType();

            int n_overloaded();
            void* getOverloadedDescriptor(int i);
            void addOverloaded(Def* def);

        private:
            SymbolKind kind;
            void* descriptor;
            std::vector<void*> overloadedDescriptors;
            int line;
            int column;
            Type* type;
    };
}

#endif // SYMBOL_H
