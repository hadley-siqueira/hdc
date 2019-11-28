#ifndef HDC_DRIVER_H
#define HDC_DRIVER_H

#include <map>
#include <string>
#include "ast/SourceFile.h"

namespace hdc {
    class Driver {
        /* Constructors */
        public:
            Driver();

        /* Destructors */
        public:
            ~Driver();

        public:
            /* This is the main entry point of the Driver class. It receives a path to the main file and
             * proceeds wit full compilation of the main file and all files included by main recursively
             */
            void compile(std::string pathToMain);

        private:
            void parseFile(std::string path);
            bool fileExists(std::string path);

        private:
            std::map<std::string, SourceFile*> sourceFiles;
    };
}

#endif
