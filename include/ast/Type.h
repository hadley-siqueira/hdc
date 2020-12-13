#ifndef HDC_TYPE_H
#define HDC_TYPE_H

#include "ast/ASTNode.h"

/* Type ranks
 * 0  - void
 * 1  - bool
 * 2  - i8
 * 3  - char
 * 4  - u8
 * 5  - uchar
 * 6  - i16
 * 7  - short
 * 8  - u16
 * 9  - ushort
 * 10 - i32
 * 11 - int
 * 12 - u32
 * 13 - uint
 * 14 - i64
 * 15 - long
 * 16 - u64
 * 17 - ulong
 * 18 - float
 * 19 - double
 */

namespace hdc {
    class Type : public ASTNode {
        public:
            virtual ~Type();

        public:
            virtual Type* clone()=0;
            virtual bool equals(Type* other);
            virtual int getRank()=0;

        public:
            virtual void accept(Visitor* visitor)=0;
    };
}

#endif
