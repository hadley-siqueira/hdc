cmake_minimum_required(VERSION 2.8)

project(hdc)
set(TOKEN_FILES src/token/Token.cpp)
set(LEX_FILES src/lex/Lex.cpp)
add_executable(${PROJECT_NAME} "src/main.cpp" ${TOKEN_FILES} ${LEX_FILES})
