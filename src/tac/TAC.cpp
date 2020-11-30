#include <sstream>
#include <iostream>
#include "tac/TAC.h"

using namespace hdc;

TAC::TAC() {
    src1 = -1;
    src2 = -1;
    dst = -1;
}

std::string TAC::to_str(bool printSets) {
    std::stringstream ss;

    switch (kind) {
    case TAC_LABEL:
        ss << label << ":";
        break;

    case TAC_RETURN:
        ss << "    return";
        break;

    case TAC_RETURN_VALUE:
        ss << "    return %" << src1;
        break;

    case TAC_END_EXPR:
        break;

    case TAC_LCALL:
        ss << "    %" << dst << " = lcall " << label;
        break;

    case TAC_PUSH_PARAM:
        ss << "    push_param %" << dst;
        break;

    case TAC_GET_VAR:
        ss << "    %" << dst << " = get_var('" << label << "')";
        break;

    case TAC_SW:
        ss << "    *%" << dst << " = %" << src1;
        break;

    case TAC_LW:
        ss << "    %" << dst << " = *%" << src1;
        break;

    case TAC_SLL:
        ss << "    %" << dst << " = %" << src1 << " << %" << src2;
        break;

    case TAC_BITWISE_AND:
        ss << "    %" << dst << " = %" << src1 << " & %" << src2;
        break;

    case TAC_BITWISE_XOR:
        ss << "    %" << dst << " = %" << src1 << " ^ %" << src2;
        break;

    case TAC_BITWISE_OR:
        ss << "    %" << dst << " = %" << src1 << " | %" << src2;
        break;


    case TAC_ADD:
        ss << "    %" << dst << " = %" << src1 << " + %" << src2;
        break;

    case TAC_SUB:
        ss << "    %" << dst << " = %" << src1 << " - %" << src2;
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
        ss << "ERROR: undefined tac:" << kind;
        break;
    }

    if (printSets) {
        ss << "\t\t\t\t\t[";
        std::set<int>::iterator it;

        for (it = before.begin(); it != before.end(); ++it) {
            ss << *it << ", ";
        }

        ss << "] - [";

        for (it = after.begin(); it != after.end(); ++it) {
          ss << *it << ", ";
        }

        ss << "]";
    }

    return ss.str();
}

bool TAC::usesTemporary(int t) {
    switch (kind) {
    case TAC_LABEL:
        return false;

    case TAC_RETURN:
        return false;

    case TAC_RETURN_VALUE:
        return t == src1;

    case TAC_END_EXPR:
        return false;

    case TAC_LCALL:
        return false;
        break;

    case TAC_PUSH_PARAM:
        return t == dst;

    case TAC_GET_VAR:
        break;

    case TAC_SW:
        return t == dst || t == src1;

    case TAC_LW:
        return t == src1;

    case TAC_SLL:
    case TAC_BITWISE_AND:
    case TAC_BITWISE_XOR:
    case TAC_BITWISE_OR:
    case TAC_ADD:
    case TAC_SUB:
        return t == src1 || t == src2;

    case TAC_IFZ:
        return t == src1;

    case TAC_GOTO:
    case TAC_CONST_I32:
        break;
    }

    return false;
}

bool TAC::generateTemporary(int t) {
    switch (kind) {
    case TAC_LABEL:
        return false;

    case TAC_RETURN:
        return false;

    case TAC_RETURN_VALUE:
        return false;

    case TAC_END_EXPR:
        return false;

    case TAC_LCALL:
        return t == dst;
        break;

    case TAC_PUSH_PARAM:
        return false;

    case TAC_GET_VAR:
        return t == dst;

    case TAC_SW:
        return false;

    case TAC_LW:
        return t == dst;

    case TAC_SLL:
    case TAC_BITWISE_AND:
    case TAC_BITWISE_XOR:
    case TAC_BITWISE_OR:
    case TAC_ADD:
    case TAC_SUB:
        return t == dst;

    case TAC_IFZ:
        return false;

    case TAC_GOTO:
        return false;

    case TAC_CONST_I32:
        return t == dst;
    }

    return false;
}
