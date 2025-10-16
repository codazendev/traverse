// File: main.cpp
// The main file for testing traverse features during development.

// System includes.

// Engine includes.
#include "traverse/Logger.hpp"

int main(int argc, char* argv[]) {
    traverse::Logger logger("demo.log");

    logger.debug("Debug log message");
    logger.debugf("Debug log message with format specifiers. Here's a string {} and a float {}.", "Wow", 3.14);
    logger.info("Info log message");
    logger.infof("Info log message with format specifiers. Here's an int {} and a char {}.", 48228, 'a');
    logger.warn("Warn log message");
    logger.warnf("Warn log message with format specifiers. Here's an octal {} and a hexadecimal {}.", 0432, 0xF12);
    logger.error("Error log message");
    logger.errorf("Error log message with format specifiers. Here's a string {} and a float {}.", "Wow", 3.14);
    logger.fatal("Fatal log message");
    logger.fatalf("Fatal log message with format specifiers. Here's a string {} and a float {}.", "Wow", 3.14);
}