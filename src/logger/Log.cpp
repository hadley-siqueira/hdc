#include "logger/Log.h"

using namespace hdc;

LogKind Log::getKind() const {
    return kind;
}

void Log::setKind(const LogKind& value) {
    kind = value;
}
