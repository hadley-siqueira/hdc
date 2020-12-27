#include <iostream>
#include <fstream>
#include <sstream>

#include "logger/Logger.h"

using namespace hdc;

Logger::Logger() {
    logParserFlag = false;
    logLexFlag = false;
    logDriverFlag = false;
    logSymbolTableFlag = false;
}

Logger::~Logger() {
    for (int i = 0; i < logs.size(); ++i) {
        delete logs[i];
    }
}

void Logger::printLogs() {
    for (int i = 0; i < logs.size(); ++i) {
        logs[i]->print();
    }
}

void Logger::setAllFlags() {
    logParser(true);
    logDriver(true);
    logLex(true);
    logSymbolTable(true);
}

void Logger::logParser(bool flag) {
    logParserFlag = flag;
}

void Logger::logDriver(bool flag) {
    logDriverFlag = flag;
}

void Logger::logLex(bool flag) {
    logLexFlag = flag;
}

void Logger::logSymbolTable(bool flag) {
    logSymbolTableFlag = flag;
}

bool Logger::enabled(LogKind kind) {
    if (kind == LOG_ERROR) return true;
    if (kind == LOG_INTERNAL_DRIVER && logDriverFlag) return true;
    if (kind == LOG_INTERNAL_LEX && logLexFlag) return true;
    if (kind == LOG_INTERNAL_PARSER && logParserFlag) return true;
    if (kind == LOG_INTERNAL_SYMBOL_TABLE && logSymbolTableFlag) return true;

    return false;
}

void Logger::log(std::string message) {
    logs.push_back(new Log(message));
}

void Logger::log(LogKind kind, std::string message) {
    if (enabled(kind)) {
        logs.push_back(new Log(kind, message));
    }
}

void Logger::log(LogKind kind, std::string message, const char *path, int line, int column) {
    if (enabled(kind)) {
        int linec = line;
        std::ifstream f;
        std::string lin;
        std::stringstream ss;

        f.open(path);

        if (linec == 1) {
            std::getline(f, lin);
        } else {
            while (linec > 0) {
                std::getline(f, lin);
                --linec;
            }
        }

        ss << "on file '" << path << "' at line " << line << ":\n";
        ss << "    " << lin << "\n    ";

        for (int i = 1; i < column; ++i) {
            ss << ' ';
        }

        ss << "^\n    " << message;
        logs.push_back(new Log(kind, ss.str()));
    }
}

void Logger::quit() {
    printLogs();
    std::cout << std::endl;
    exit(0);
}
