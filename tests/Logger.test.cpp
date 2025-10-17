// File: Logger.test.cpp
// Tests for the Logger class.

// System includes.
#include <string>
#include <filesystem>

// Engine includes.
#include "traverse/Logger.hpp"

// Catch2 includes.
#include <catch2/catch_test_macros.hpp>

TEST_CASE("traverse::Logger::levelToString", "[Logger]") {
    std::string log_file_name = "log_test_" + std::to_string(random()) + ".log";
    
    REQUIRE_FALSE(std::filesystem::exists(log_file_name));

    traverse::Logger logger(log_file_name);
    
    REQUIRE(std::filesystem::exists(log_file_name));
    
    logger.debug("Test debug message");
}