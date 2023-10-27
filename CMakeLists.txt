cmake_minimum_required(VERSION 3.20)
project(Readability_scorer)

add_library(READ_FUNC_LIB SHARED
    src/word_attributes.c
    src/readFile.c
    src/add.c
    src/coleman.c
    src/auto_readability.c
)

target_include_directories(READ_FUNC_LIB PUBLIC
    "include"
)

set(EXECUTABLE_FILE
    Readability_scorer
)

add_executable(${EXECUTABLE_FILE} src/main.c)

# Include the "include" directory for the executable target
target_include_directories(${EXECUTABLE_FILE} PUBLIC
    "include"
)

target_link_libraries(${EXECUTABLE_FILE} READ_FUNC_LIB)
