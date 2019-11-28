#include <iostream>

#include "logger/Log.h"

using namespace hdc;

Log::Log(LogKind kind, std::string message) {
    this->kind = kind;
    this->message = message;
}

Log::~Log() {

}

LogKind Log::getKind() const {
    return kind;
}

void Log::setKind(const LogKind& value) {
    kind = value;
}

std::string Log::getMessage() const {
    return message;
}

void Log::setMessage(const std::string& value) {
    message = value;
}

void Log::print() {
    switch (kind) {
    case LOG_INTERNAL_DRIVER:
        std::cout << "\033[34mDriver: \u001b[0m" << message << std::endl;
        break;

    case LOG_ERROR:
        std::cout << "\u001b[31mError: \u001b[0m" << message << std::endl;
        break;
    }
}
