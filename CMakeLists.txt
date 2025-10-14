cmake_minimum_required(VERSION 3.15)
project(TraverseEngine VERSION 0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Engine library
add_library(traverse)
target_include_directories(traverse PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Sandbox testing executable
add_executable(sandbox
    sandbox/main.cpp)

# Unit testing executable
add_executable(test_traverse)