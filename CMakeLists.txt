# Set minimum required CMake version
cmake_minimum_required(VERSION 3.25)

# Define traverse engine project, version, and its languages used
project(TraverseEngine
    VERSION 0.0
    LANGUAGES CXX
)

# Set CXX standard and make it required
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set project output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# Generate compile_commands.json and place it at project root (for convenience with clangd and my sanity)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_SOURCE_DIR}/compile_commands.json)

# Engine library
add_library(
    traverse
    STATIC
    src/Logger.cpp
)

# Declare the traverse engine's header path
target_include_directories(traverse PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Demo testing executable
add_executable(
    demo
    demo/main.cpp
)

# Link the demo executable to the traverse engine library
target_link_libraries(demo PRIVATE traverse)

# Unit testing executable
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.2
)
FetchContent_MakeAvailable(Catch2)

enable_testing()
add_executable(
    test_traverse
    tests/Logger.test.cpp
)
target_link_libraries(test_traverse PRIVATE traverse Catch2::Catch2WithMain)
include(CTest)
include(Catch)
catch_discover_tests(test_traverse)