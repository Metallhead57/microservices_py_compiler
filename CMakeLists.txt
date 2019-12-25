cmake_minimum_required(VERSION 3.5)

project(code_gen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PythonLibs 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

FILE(GLOB_RECURSE LibFiles "./*.h")
add_custom_target(headers SOURCES ${LibFiles})

add_executable(code_gen main.cpp
    Blocks/SimpleBlock.cpp
    codegenerator.cpp
    Blocks/IBlock.cpp
    runner.cpp
    Blocks/FunctionBlock.cpp
    Blocks/ConditionBlock.cpp
    Blocks/WhileBlock.cpp
    blockparser.cpp
    Blocks/ReturnBlock.cpp
    testparser.cpp
    inputargument.cpp)

target_link_libraries(code_gen ${PYTHON_LIBRARIES} zmq)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/example.json
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_example.json
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

