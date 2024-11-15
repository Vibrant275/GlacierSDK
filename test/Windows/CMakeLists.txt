# CMake configuration for Prismio project on Windows
cmake_minimum_required(VERSION 3.14)
project(Prismio LANGUAGES CXX)

set(BINARY_NAME "dfg")
set(CMAKE_CXX_STANDARD 23)
add_definitions(-DUNICODE -D_UNICODE)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(${BINARY_NAME} ${SOURCES})
target_include_directories(${BINARY_NAME} PRIVATE include)
install(TARGETS ${BINARY_NAME} DESTINATION bin)
