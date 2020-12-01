#ifndef HDC_TACADD_H
#define HDC_TACADD_H

#include "TAC.h"

namespace hdc {
    class TACAdd : public TAC {
    public:
        TACAdd(int dst, int src1, int src2);

    public:
        int getDestination();
        int getSource1();
        int getSource2();

    private:
        int dst;
        int src1;
        int src2;
    };
}

#endif // TACADD_H
