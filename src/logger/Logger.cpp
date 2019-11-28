#include "logger/Logger.h"

hdc::Logger::Logger() {
    logParserFlag = false;
    logLexFlag = false;
    logDriverFlag = false;
}

hdc::Logger::~Logger() {
    for (int i = 0; i < logs.size(); ++i) {
        delete logs[i];
    }
}

void hdc::Logger::printLogs() {
    for (int i = 0; i < logs.size(); ++i) {
        logs[i]->print();
    }
}

void hdc::Logger::logParser(bool flag) {
    logParserFlag = flag;
}

void hdc::Logger::logDriver(bool flag) {
    logDriverFlag = flag;
}

void hdc::Logger::logLex(bool flag) {
    logLexFlag = flag;
}

void hdc::Logger::log(hdc::LogKind kind, std::string message) {
    /*if (kind == LOG_INTERNAL_DRIVER && !logDriverFlag) return;
    if (kind == LOG_INTERNAL_LEX && !logLexFlag) return;
    if (kind == LOG_INTERNAL_PARSER && !logParserFlag) return;*/

    logs.push_back(new Log(kind, message));
}
