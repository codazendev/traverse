cmake_minimum_required(VERSION 3.15)
project(TraverseEngine VERSION 0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Generate compile_commands.json and place it at project root
execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_SOURCE_DIR}/compile_commands.json)

# Engine library
add_library(traverse
    src/Logger.cpp)
target_include_directories(traverse PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Sandbox testing executable
add_executable(sandbox
    sandbox/main.cpp)

# Unit testing executable
add_executable(test_traverse
    tests/Logger.test.cpp)
target_link_libraries(test_traverse PRIVATE traverse)