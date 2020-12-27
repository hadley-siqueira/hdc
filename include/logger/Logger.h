#ifndef HDC_LOGGER_H
#define HDC_LOGGER_H

#include <vector>
#include <string>
#include "logger/Log.h"

namespace hdc {
    class Logger {
        /* Constructors */
        public:
            Logger();

        /* Destructors */
        public:
            ~Logger();

        public:
            void log(std::string message);
            void log(LogKind kind, std::string message);
            void log(LogKind kind, std::string message, const char* path, int line, int column);
            void quit();

            void printLogs();

            void setAllFlags();
            void logParser(bool flag);
            void logDriver(bool flag);
            void logLex(bool flag);
            void logSymbolTable(bool flag);

        private:
            bool enabled(LogKind kind);


        private:
            std::vector<Log*> logs;
            bool logParserFlag;
            bool logDriverFlag;
            bool logLexFlag;
            bool logSymbolTableFlag;
    };
}

#endif
