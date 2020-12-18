#include "logger/Logger.h"

using namespace hdc;

Logger::Logger() {
    logParserFlag = false;
    logLexFlag = false;
    logDriverFlag = false;
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

void Logger::log(std::string message) {
    logs.push_back(new Log(message));
}

void Logger::log(LogKind kind, std::string message) {
    if (kind == LOG_INTERNAL_DRIVER && !logDriverFlag) return;
    if (kind == LOG_INTERNAL_LEX && !logLexFlag) return;
    if (kind == LOG_INTERNAL_PARSER && !logParserFlag) return;

    logs.push_back(new Log(kind, message));
}

void Logger::quit() {
    printLogs();
    exit(0);
}
