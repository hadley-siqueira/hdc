#include <iostream>

#include "logger/Log.h"

using namespace hdc;

Log::Log(std::string message) {
    this->message = message;
}

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
    case LOG_ERROR:
        std::cout << "\u001b[31mError: \u001b[0m" << message << std::endl;
        break;

    case LOG_WARNING:
        std::cout << "Warning: " << message << std::endl;
        break;

    case LOG_INFO:
        std::cout << "Info: " << message << std::endl;
        break;

    case LOG_INTERNAL_DRIVER:
        std::cout << "\033[34mDriver: \u001b[0m" << message << std::endl;
        break;

    case LOG_INTERNAL_LEX:
        std::cout << "Lex: " << message << std::endl;
        break;

    case LOG_INTERNAL_PARSER:
        std::cout << "Parser: " << message << std::endl;
        break;

    case LOG_INTERNAL_SYMBOL_TABLE:
        std::cout << "SymbolTable: " << message << std::endl;
        break;
    }
}
