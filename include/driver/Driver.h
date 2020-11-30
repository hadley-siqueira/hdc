#ifndef HDC_DRIVER_H
#define HDC_DRIVER_H

#include <map>
#include <string>
#include <vector>

#include "ast/SourceFile.h"
#include "logger/Logger.h"
#include "tac/TAC.h"

namespace hdc {
    class Driver {
        /* Constructors */
        public:
            Driver();

        /* Destructors */
        public:
            ~Driver();

        public:
            void run();
            void setFlags(int argc, char* argv[]);
            void parseProgram();
            void showLogs();
            void foobar();

        private:
            void buildSymbolTables();
            void generateTAC();
            void generate_x86_64();
            void prettyPrintAllFiles();

            SourceFile* parseFile(std::string path);
            void parseImports(SourceFile* file);
            void parseImport(Import* import);
            void parseSimpleImport(Import* import);
            void parseMultipleImport(Import* import);
            bool fileExists(std::string path);
            std::string buildPathForImport(Import* import);
            std::string buildPathForMultipleImport(Import* import);

            void setRootPathFromMainFile();

            std::vector<std::string> getFilesFromDirectory(std::string path, int& err);

        private:
            std::map<std::string, SourceFile*> sourceFiles;
            Logger logger;
            std::string mainFilePath;
            std::string rootPath;
            char pathDelimiter;

            std::vector<TAC> tacs;
    };
}

#endif
