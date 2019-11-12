cmake_minimum_required(VERSION 2.8)
project(hdc)

include_directories(include)

set(TOKEN_SRC src/token/Token.cpp)
set(LEX_SRC src/lex/Lex.cpp)
set(SOURCES ${TOKEN_SRC} ${LEX_SRC} src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
