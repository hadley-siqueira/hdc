#include <sstream>
#include <iostream>
#include "tac/TAC.h"

using namespace hdc;

std::string TAC::to_str() {
    std::stringstream ss;

    switch (kind) {
    case TAC_LABEL:
        ss << label << ":";
        break;

    case TAC_ADD:
        ss << "    %" << dst << " = %" << src1 << " + %" << src2;
        break;

    case TAC_IFZ:
        ss << "    if !%" << src1 << " goto " << label;
        break;

    case TAC_GOTO:
        ss << "    goto " << label;
        break;

    case TAC_CONST_I32:
        ss << "    %" << dst << " = " << label;
        break;

    default:
        ss << "ERROR: undefined tac";
        break;
    }

    return ss.str();
}
