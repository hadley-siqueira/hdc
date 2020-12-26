#ifndef HDC_DRIVER_H
#define HDC_DRIVER_H

#include <map>
#include <string>
#include <vector>

#include "ast/Program.h"
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
            void generateIR();
            void generate_x86_64();
            void generateCpp();
            void prettyPrintAllFiles();
            void callCppCompiler();

            SourceFile* parseFile(std::string path);
            void parseImports(SourceFile* file);
            void parseImport(Import* import);
            void parseSimpleImport(Import* import);
            void parseMultipleImport(Import* import);
            bool fileExists(std::string path);
            std::string buildPathForImport(Import* import);
            std::string buildPathForMultipleImport(Import* import);
            std::string getEnvPath(std::string key);
            void configureSearchPath();

            void setRootPathFromMainFile();

            std::vector<std::string> getFilesFromDirectory(std::string path, int& err);

        private:
            Program program;
            Logger logger;
            std::string mainFilePath;
            std::string rootPath;
            std::string outputName;
            std::vector<std::string> searchPath;
            char pathDelimiter;

            std::vector<TAC> tacs;

            // flags
            bool emitCppFlag;
    };
}

#endif
