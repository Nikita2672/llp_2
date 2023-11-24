cmake_minimum_required(VERSION 3.26)
project(parser C)

set(CMAKE_C_STANDARD 11)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

set(BISON_INPUT_FILE parser.y)
set(FLEX_INPUT_FILE lexer.l)

BISON_TARGET(MyParser ${BISON_INPUT_FILE} ${CMAKE_CURRENT_SOURCE_DIR}/parser.c)
FLEX_TARGET(MyLexer ${FLEX_INPUT_FILE} ${CMAKE_CURRENT_SOURCE_DIR}/lexer.c)
ADD_FLEX_BISON_DEPENDENCY(MyLexer MyParser)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(parser main.c ${BISON_MyParser_OUTPUTS} ${FLEX_MyLexer_OUTPUTS})
