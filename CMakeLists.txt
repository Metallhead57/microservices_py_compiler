cmake_minimum_required(VERSION 3.5)

project(code_gen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PythonLibs 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

FILE(GLOB_RECURSE LibFiles "./*.h")
add_custom_target(headers SOURCES ${LibFiles})

add_executable(code_gen main.cpp
    helloworldblock.cpp
    codegenerator.cpp
    IBlock.cpp
    runner.cpp
    funcinputblock.cpp
    conditionalblock.cpp
    whileblock.cpp
    json_parser.cpp
    returnblock.cpp)

target_link_libraries(code_gen ${PYTHON_LIBRARIES})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/example.json
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

