#ifndef HDC_LOG_H
#define HDC_LOG_H

namespace hdc {
    typedef enum LogKind {
        LOG_ERROR,
        LOG_WARNING,
        LOG_INFO,
        LOG_INTERNAL
    } LogKind;

    class Log {
        /* Constructors */
        public:
            Log();

        /* Destructors */
        public:
            ~Log();

            LogKind getKind() const;
            void setKind(const LogKind& value);

        private:
            LogKind kind;
    };
}

#endif
