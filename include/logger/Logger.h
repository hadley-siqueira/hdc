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
            void log(LogKind kind, std::string message);

            void printLogs();

            void logParser(bool flag);
            void logDriver(bool flag);
            void logLex(bool flag);

        private:
            std::vector<Log*> logs;
            bool logParserFlag;
            bool logDriverFlag;
            bool logLexFlag;
    };
}

#endif
