#ifndef HDC_LOG_H
#define HDC_LOG_H

#include <string>

namespace hdc {
    typedef enum LogKind {
        LOG_ERROR,
        LOG_WARNING,
        LOG_INFO,
        LOG_INTERNAL_DRIVER,
        LOG_INTERNAL_LEX,
        LOG_INTERNAL_PARSER
    } LogKind;

    class Log {
        /* Constructors */
        public:
            Log();
            Log(LogKind kind, std::string message);

        /* Destructors */
        public:
            ~Log();

            LogKind getKind() const;
            void setKind(const LogKind& value);

            std::string getMessage() const;
            void setMessage(const std::string& value);

            void print();

        private:
            LogKind kind;
            std::string message;

    };
}

#endif
