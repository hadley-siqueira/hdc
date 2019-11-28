#ifndef HDC_LOGGER_H
#define HDC_LOGGER_H

#include <vector>
#include "logger/Log.h"

namespace hdc {
    class Logger {
        /* Constructors */
        public:
            Logger();

        /* Destructors */
        public:
            ~Logger();

        private:
            std::vector<Log*> logs;
    }
}

#endif
